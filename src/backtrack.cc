/**
 * @file backtrack.cc
 *
 */

#include "backtrack.h"
#include <map>
#include <queue>
#include <algorithm>
#include <unordered_set>
#include <stdlib.h>

Backtrack::Backtrack() {}
Backtrack::~Backtrack() {}


std::unordered_set<Vertex> visit;      //visited data vertices during backtracking
std::vector<std::vector<size_t>> extendable_vertices;        // list of extendable data vertices in each query node
typedef std::pair<size_t, Vertex> pi;
size_t count=0; //check number of matching result

void Backtrack::BuildDAG(const Graph &data, const Graph &query, const CandidateSet &cs)
{
    std::cout << "t " << query.GetNumVertices() << "\n";

    size_t query_size = query.GetNumVertices();
    std::map<Label, std::vector<Vertex> > label_map;

    std::vector<std::vector<Vertex> > cs_list;
    cs_list.resize(query_size);

    labels.resize(query_size);
    degrees.resize(query_size);
    cs_size.resize(query_size);
    //making label-query vertex map
    for (size_t j = 0; j < query_size; j++)
    {
        cs_size[j] = cs.GetCandidateSize(j);
        degrees[j] = query.GetDegree(j);
        Label l = query.GetLabel(j);
        labels[j] = l;
        if (label_map.count(l) == 0)
        {
            std::vector<Vertex> vertices;
            vertices.push_back(j);
            label_map.insert(std::make_pair(l, vertices));
            label_frequencies.insert(std::make_pair(l, data.GetLabelFrequency(l)));
        }

        else
        {
            label_map.find(l)->second.push_back(j);
        }
    }

    //finding root (given cs version)
    double min = (double)cs.GetCandidateSize(0)/query.GetDegree(0);
    root = 0;
    for (size_t j = 1; j < query_size; j++)
    {
        double CDD = (double)cs.GetCandidateSize(j)/query.GetDegree(j);
        if (CDD < min){
            min = CDD;
            root = j;
        }

    }


    //Build DAG using BFS

    dag_adj_list.resize(query_size);
    dag_parent_list.resize(query_size);
    std::vector<bool> visited;
    visited.resize(query_size);
    for (size_t j = 0; j < query_size; j++)
    {
        visited[j] = false;
    }
    visited[root] = true;
    std::queue<Vertex> Q;
    Q.push(root);
    while (!Q.empty())
    {
        Vertex u = Q.front();
        Q.pop();

        size_t start_offset = query.GetNeighborStartOffset(u);
        size_t end_offset = query.GetNeighborEndOffset(u);
        std::vector<Vertex> neighbor;
        neighbor.resize(query.GetDegree(u));
        for (size_t i = start_offset; i < end_offset; i++)
        {
            neighbor[i - start_offset] = query.GetNeighbor(i);
        }

        //  sort neighbor by descending order of candidate size and descending order of degree second
        std::sort(neighbor.begin(), neighbor.end(), [this](Vertex u, Vertex v) {
            if (cs_size[u] != cs_size[v])
                return cs_size[u]>cs_size[v];
            else if (GetDegree(u) != GetDegree(v))
                return GetDegree(u) > GetDegree(v);
            else
                return u < v;
        });
        for (Vertex v : neighbor)
        {
            if (!visited[v])
            {
                dag_adj_list[u].push_back(v);
                visited[v] = true;
                Q.push(v);
            }
            else
            {
                if (std::find(dag_adj_list[v].begin(), dag_adj_list[v].end(), u) == dag_adj_list[v].end())
                {
                    dag_adj_list[u].push_back(v);
                }
                else
                {
                    dag_parent_list[u].push_back(v);
                }
            }
        }
    }

    dag_adj_array.resize(2 * query.GetNumEdges());
    parent_start_offset.resize(query_size + 1);
    child_start_offset.resize(query_size);
    parent_start_offset[0] = 0;

    for (size_t i = 0; i < query_size; ++i)
    {
        parent_start_offset[i + 1] = parent_start_offset[i] + query.GetNeighborEndOffset(i) - query.GetNeighborStartOffset(i);
        child_start_offset[i] = parent_start_offset[i + 1] - dag_adj_list[i].size();

        std::copy(dag_parent_list[i].begin(), dag_parent_list[i].end(),
                  dag_adj_array.begin() + parent_start_offset[i]);

        std::copy(dag_adj_list[i].begin(), dag_adj_list[i].end(), dag_adj_array.begin() + child_start_offset[i]);
    }
}

void Backtrack::PrintAllMatches(const Graph &data, const Graph &query,
                                const CandidateSet &cs)
{
    BuildDAG(data, query, cs);
    std::map<Vertex, Vertex> M;
    std::priority_queue<pi, std::vector<pi>, std::greater<pi> > extendable;
    origin_data=data;
    extendable_vertices.resize(query.GetNumVertices());
    BackTrack(query, cs, M, extendable);
}

//recursive function to find subgraph
void Backtrack::BackTrack(const Graph &query, const CandidateSet &cs, std::map<Vertex, Vertex> &M, std::priority_queue<pi, std::vector<pi>, std::greater<pi> > &extendable)
{
    // stop one cycle if one of the query vertex's cs is all used.
    if(!isAllUsed(query,cs,visit,M)) {


        size_t query_size = query.GetNumVertices();

        if (M.size() == query_size) {
            // stdout the matching result
            count++;
            std::cout<<"a";
            auto iter = M.begin();
            while (iter != M.end()) {
                std::cout<<" "<<iter->second;
                iter++;
            }
            std::cout<<"\n";
            if(count==100000){
                exit(0);
            }

        }

            // begin at root
        else if (M.size() == 0) {
            size_t csize = cs.GetCandidateSize(root);
            for (size_t i = 0; i < csize; i++) {
                std::priority_queue<pi, std::vector<pi>, std::greater<pi> > extendable_prime;
                M.insert(std::pair<Vertex, Vertex>(root, cs.GetCandidate(root, i)));

                // push child node if it is all connected with its parents
                for (size_t j = child_start_offset[root]; j < parent_start_offset[root + 1]; j++) {
                    if (isExtendable(dag_adj_array[j], M)) {
                        extendable_prime.push(
                                std::make_pair(ExtendableVertices(dag_adj_array[j], M, cs), dag_adj_array[j]));
                    }
                }

                visit.insert(cs.GetCandidate(root, i));
                BackTrack(query, cs, M, extendable_prime);
                M.erase(root);
                visit.erase(cs.GetCandidate(root, i));


            }
        } else {

            Vertex u;
            u = extendable.top().second; // query vertex to be searched
            extendable.pop();
            //only consider
            for (size_t j = 0; j < extendable_vertices[u].size(); j++)
            {
                Vertex v = extendable_vertices[u][j];

                // only consider unvisited vertex
                if (visit.find(v) == visit.end())
                {

                        M.insert(std::pair<Vertex, Vertex>(u, v));


                        std::priority_queue<pi, std::vector<pi>, std::greater<pi> > extendable_prime = extendable;

                        //put extendable child to priority queue
                        for (size_t j = child_start_offset[u]; j < parent_start_offset[u + 1]; j++) {
                            if (isExtendable(dag_adj_array[j], M)) {
                                extendable_prime.push(
                                        std::make_pair(ExtendableVertices(dag_adj_array[j], M, cs), dag_adj_array[j]));
                            }
                        }
                        visit.insert(v);
                        BackTrack(query, cs, M, extendable_prime);
                        M.erase(u);

                        visit.erase(v);
                    }
                }
            }
        }
    }

// return true if all u's parents are included in M
bool Backtrack::isExtendable(Vertex u, const std::map<Vertex, Vertex> &M)
{
    for (size_t i = parent_start_offset[u]; i < child_start_offset[u]; i++)
    {
        if (M.find(dag_adj_array[i]) == M.end())
        {
            return false;
        }
    }
    return true;
}

// return the number of extendable vertices in child cs, and store that vertices.
size_t Backtrack::ExtendableVertices(Vertex u, const std::map<Vertex,Vertex> &M, const CandidateSet &cs){

    size_t extendable_count=0;
    std::vector<size_t> possible_vertices;
    for(size_t i = 0; i < cs.GetCandidateSize(u); i++){
        size_t counter=0;
        for(size_t j = parent_start_offset[u]; j < child_start_offset[u]; j++){
            if(origin_data.IsNeighbor(M.at(dag_adj_array[j]),cs.GetCandidate(u,i))){
                counter++;
            }
        }
        if(counter == child_start_offset[u] - parent_start_offset[u]){
            extendable_count++;
            possible_vertices.push_back(cs.GetCandidate(u,i));
        }
    }
    extendable_vertices[u]=possible_vertices;
    return extendable_count;
}

// return true if cs of unvisited query vertex is all used
bool Backtrack::isAllUsed(const Graph &query, const CandidateSet &cs, std::unordered_set<Vertex> &visited,std::map<Vertex, Vertex> &M) {
    for(size_t i = 0; i < query.GetNumVertices(); i++){
        if(M.find(i)==M.end()) {
            size_t remaining = cs.GetCandidateSize(i);
            for (size_t j = 0; j < cs.GetCandidateSize(i); j++) {
                if (visited.find(cs.GetCandidate(i, j)) != visited.end()) {
                    remaining--;
                }
            }
            if (remaining == 0) {
                return true;
            }
        }
    }
    return false;
}
