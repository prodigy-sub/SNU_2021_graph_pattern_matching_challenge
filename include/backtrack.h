/**
 * @file backtrack.h
 *
 */

#ifndef BACKTRACK_H_
#define BACKTRACK_H_

#include "candidate_set.h"
#include "common.h"
#include "graph.h"
#include <map>
#include <queue>
#include <iostream>
#include <unordered_set>
typedef std::pair<size_t, Vertex> pi;
class Backtrack
{
public:
    Backtrack();
    ~Backtrack();
    void BuildDAG(const Graph &data, const Graph &query, const CandidateSet &cs);
    void PrintAllMatches(const Graph &data, const Graph &query,
                         const CandidateSet &cs);
    bool isExtendable(Vertex u, const std::map<Vertex, Vertex> &M);
    size_t ExtendableVertices(Vertex u, const std::map<Vertex,Vertex> &M, const CandidateSet &cs);
    void BackTrack(const Graph &query, const CandidateSet &cs, std::map<Vertex, Vertex> &M, std::priority_queue<pi, std::vector<pi>, std::greater<pi> > &extendable);
    bool isAllUsed(const Graph &query, const CandidateSet &cs, std::unordered_set<Vertex> &visited,std::map<Vertex, Vertex> &M );


    inline size_t GetDegree(Vertex v) const;
private:
    Graph origin_data=Graph("C:/Users/cssen/CLionProjects/Graph-Pattern-Matching-Challenge-master/data/lcc_hprd.igraph", false);
    std::map<Label, size_t> label_frequencies; //label frequency of query vertex in data graph
    std::vector<Label> labels;                 //label of each query vertex
    std::vector<size_t> degrees;               //degree of each query vertex
    std::vector<size_t> cs_size;               //candidate size of each query vertex

    std::vector<std::vector<Vertex> > dag_adj_list;
    std::vector<std::vector<Vertex> > dag_parent_list;
    std::vector<Vertex> dag_adj_array;
    std::vector<size_t> parent_start_offset;
    std::vector<size_t> child_start_offset;

    Vertex root;
};


/**
 * @brief Returns the degree of the vertex v in query.
 *
 * @param v vertex id.
 * @return size_t
 */
inline size_t Backtrack::GetDegree(Vertex v) const
{
    return degrees[v];
}



#endif // BACKTRACK_H_
