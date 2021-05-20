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

void Backtrack::PrintAllMatches(const Graph &data, const Graph &query,
                                const CandidateSet &cs) {
  std::cout << "t " << query.GetNumVertices() << "\n";

  size_t graph_size = data.GetNumVertices();
  size_t query_size = query.GetNumVertices();
  std::map<Label,std::vector<Vertex>> label_map;

  std::vector<std::vector<Vertex>> cs_list;
  cs_list.resize(query_size);

  size_t query_label_num = query.GetNumLabels();

  //query 한번돌면서 label-query vertex map 생성
  for(size_t j=0;j<query_size;j++){

      Label l = query.GetLabel(j);

      if(label_map.count(l)==0){
          std::vector<Vertex> vertices;
          vertices.push_back(j);
          label_map.insert(std::make_pair(l,vertices));
      }

      else{
          label_map.find(l)->second.push_back(j);
      }
  }
  //data 돌면서 matching
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
  double min= (double)cs_list[0].size()/query.GetDegree(0);;
  Vertex root = 0;
  for(size_t j=1;j<query_size;j++){
      double CDD = (double)cs_list[j].size()/query.GetDegree(j);
      if(CDD<min){
          min=CDD;
          root=j;
      }
  }
  //BFS
  std::vector<std::vector<Vertex>> dag_adj_list;
  dag_adj_list.resize(query_size);
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
          }
      }
  }
   //DAG 잘 되는지 확인용
    /*
    size_t count=0;
    size_t edge_num=0;
    for(std::vector<Vertex> iter : dag_adj_list){
        std::cout<<count<<"  ";
        for(Vertex i : iter){
            std::cout<<i<<" ";
            edge_num++;
        }
        std::cout<<"\n";
        count++;
    }
    std::cout<<edge_num<<" "<<query.GetNumEdges()<<"\n";
    */

    //BackTracking 맡긴다 동섭
    std::vector<Vertex> M;
    while (M.size()==query_size){
        if(M.size()==0){
            //for(Vertex v : )
        }
    }

}
