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

class Backtrack {
 public:
  Backtrack();
  ~Backtrack();
  void BuildDAG(const Graph &data, const Graph &query);
  void PrintAllMatches(const Graph &data, const Graph &query,
                       const CandidateSet &cs);

  inline Label GetLabel(Vertex v) const;
  inline size_t GetLabelFrequencyInData(Label l) const;
  inline size_t GetDegree(Vertex v) const;


 private:
    std::map<Label,size_t> label_frequencies;   //label frequency of query vertex in data graph
    std::vector<Label> labels;                  //label of each query vertex
    std::vector<size_t> degrees;                //degree of each query vertex

    std::vector<std::vector<Vertex>> dag_adj_list;
    std::vector<std::vector<Vertex>> dag_parent_list;
    std::vector<Vertex> dag_adj_array;
    std::vector<size_t> parent_start_offset;
    std::vector<size_t> child_start_offset;

    Vertex root;

};


/**
 * @brief Returns the frequency of the label l in the graph.
 *
 * @param l label id.
 * @return size_t
 */
inline size_t Backtrack::GetLabelFrequencyInData(Label l) const {
    return label_frequencies.at(l);
}
/**
 * @brief Returns the degree of the vertex v in query.
 *
 * @param v vertex id.
 * @return size_t
 */
inline size_t Backtrack::GetDegree(Vertex v) const {
    return degrees[v];
}
/**
 * @brief Returns the label of the vertex v in query.
 *
 * @param v vertex id.
 * @return Label
 */
inline Label Backtrack::GetLabel(Vertex v) const { return labels[v]; }
#endif  // BACKTRACK_H_
