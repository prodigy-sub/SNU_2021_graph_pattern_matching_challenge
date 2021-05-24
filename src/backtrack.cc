/**
 * @file backtrack.cc
 *
 */

#include "backtrack.h"
#include <map>
#include <queue>
#include <algorithm>

Backtrack::Backtrack() {}
Backtrack::~Backtrack() {}

//compare func for sorting neighbor while building dag
void Backtrack::BuildDAG(const Graph &data, const Graph &query) {
    std::cout << "t " << query.GetNumVertices() << "\n";

    size_t graph_size = data.GetNumVertices();
    size_t query_size = query.GetNumVertices();
    std::map<Label,std::vector<Vertex>> label_map;

    std::vector<std::vector<Vertex>> cs_list;
    cs_list.resize(query_size);

    size_t query_label_num = query.GetNumLabels();
    labels.resize(query_size);
    degrees.resize(query_size);
    //making label-query vertex map
    for(size_t j=0;j<query_size;j++){
        degrees[j]=query.GetDegree(j);
        Label l = query.GetLabel(j);
        labels[j] = l;
        if(label_map.count(l)==0){
            std::vector<Vertex> vertices;
            vertices.push_back(j);
            label_map.insert(std::make_pair(l,vertices));
            label_frequencies.insert(std::make_pair(l,data.GetLabelFrequency(l)));
        }

        else{
            label_map.find(l)->second.push_back(j);
        }
    }
    //making initial cs
    for(size_t i=0;i<graph_size;i++){

        Label l = data.GetLabel(i);

        if(label_map.count(l)==0){
            continue;
        }

        else{
            for (Vertex v : label_map.find(l)->second){
                if(query.GetDegree(v)>data.GetDegree(i)){
                    continue;
                }
                else{
                    cs_list[v].push_back(i);
                }
            }
        }

    }
    //finding root
    double min= (double)cs_list[0].size()/query.GetDegree(0);
    root = 0;
    for(size_t j=1;j<query_size;j++){
        double CDD = (double)cs_list[j].size()/query.GetDegree(j);
        if(CDD<min){
            min=CDD;
            root=j;
        }
    }

    //BFS

    dag_adj_list.resize(query_size);
    dag_parent_list.resize(query_size);
    std::vector<bool> visited;
    visited.resize(query_size);
    for (size_t j=0;j<query_size;j++){
        visited[j]=false;
    }
    visited[root]=true;
    std::queue<Vertex> Q;
    Q.push(root);
    while(!Q.empty()){
        Vertex u = Q.front();
        Q.pop();

        size_t start_offset = query.GetNeighborStartOffset(u);
        size_t end_offset = query.GetNeighborEndOffset(u);
        std::vector<Vertex> neighbor;
        neighbor.resize(query.GetDegree(u));
        for (size_t i=start_offset;i<end_offset;i++){
            neighbor[i-start_offset]=query.GetNeighbor(i);
        }
        // sort neighbor by ascending order of label frequency in data first,
        // and descending order of degree second
        std::sort(neighbor.begin(), neighbor.end(), [this](Vertex u, Vertex v) {
            if (GetLabelFrequencyInData(GetLabel(u)) != GetLabelFrequencyInData(GetLabel(v)))
                return GetLabelFrequencyInData(GetLabel(u)) < GetLabelFrequencyInData(GetLabel(v));
            else if (GetDegree(u) != GetDegree(v))
                return GetDegree(u) > GetDegree(v);
            else
                return u < v;
        });
        for(Vertex v : neighbor){
            if(!visited[v]){
                dag_adj_list[u].push_back(v);
                visited[v]=true;
                Q.push(v);
            }
            else{
                if(std::find(dag_adj_list[v].begin(), dag_adj_list[v].end(), u)==dag_adj_list[v].end()){
                    dag_adj_list[u].push_back(v);
                }                 //이미 리스트에 있는지 계속 확인하는거 살짝 효율 아쉬움
                else{
                    dag_parent_list[u].push_back(v);
                }
            }
        }
    }

    dag_adj_array.resize(2*query.GetNumEdges());
    parent_start_offset.resize(query_size+1);
    child_start_offset.resize(query_size);
    parent_start_offset[0] = 0;

    for (size_t i = 0; i < query_size; ++i) {
        parent_start_offset[i + 1] = parent_start_offset[i] + query.GetNeighborEndOffset(i)-query.GetNeighborStartOffset(i);
        child_start_offset[i]=parent_start_offset[i+1]-dag_adj_list[i].size();

        std::copy(dag_parent_list[i].begin(), dag_parent_list[i].end(),
                  dag_adj_array.begin() + parent_start_offset[i]);

        std::copy(dag_adj_list[i].begin(), dag_adj_list[i].end(), dag_adj_array.begin()+child_start_offset[i]);

    }


}

void Backtrack::PrintAllMatches(const Graph &data, const Graph &query,
                                const CandidateSet &cs) {
    Backtrack::BuildDAG(data,query);


    //BackTracking 맡긴다 동섭
    /*
    std::vector<Vertex> M;
    while (M.size()==query_size){
        if(M.size()==0){
            //for(Vertex v : )
        }
    }
    */
}
