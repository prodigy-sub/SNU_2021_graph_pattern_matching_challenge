/**
 * @file backtrack.cc
 *
 */

#include "backtrack.h"
#include <map>
#include <queue>
#include <algorithm>
#include <unordered_set>

Backtrack::Backtrack() {}
Backtrack::~Backtrack() {}

// visit는 cs(data)의 node들
std::unordered_set<Vertex> visit;
// extendable은 dag의 node들
// https://www.geeksforgeeks.org/priority-queue-of-pairs-in-c-ordered-by-first/ 코드 참조
typedef std::pair<size_t, Vertex> pi;
// pi 의 첫번째 원소 : Candidate size, 두번째 원소 : vertex
std::priority_queue<pi, std::vector<pi>, std::greater<pi> > extendable;

//compare func for sorting neighbor while building dag
void Backtrack::BuildDAG(const Graph &data, const Graph &query)
{
    std::cout << "t " << query.GetNumVertices() << "\n";

    size_t graph_size = data.GetNumVertices();
    size_t query_size = query.GetNumVertices();
    std::map<Label, std::vector<Vertex> > label_map;

    std::vector<std::vector<Vertex> > cs_list;
    cs_list.resize(query_size);

    size_t query_label_num = query.GetNumLabels();
    labels.resize(query_size);
    degrees.resize(query_size);
    //making label-query vertex map
    for (size_t j = 0; j < query_size; j++)
    {
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
    //making initial cs
    for (size_t i = 0; i < graph_size; i++)
    {

        Label l = data.GetLabel(i);

        if (label_map.count(l) == 0)
        {
            continue;
        }

        else
        {
            for (Vertex v : label_map.find(l)->second)
            {
                if (query.GetDegree(v) > data.GetDegree(i))
                {
                    continue;
                }
                else
                {
                    cs_list[v].push_back(i);
                }
            }
        }
    }
    //finding root
    double min = (double)cs_list[0].size() / query.GetDegree(0);
    root = 0;
    for (size_t j = 1; j < query_size; j++)
    {
        double CDD = (double)cs_list[j].size() / query.GetDegree(j);
        if (CDD < min)
        {
            min = CDD;
            root = j;
        }
    }

    //BFS

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
                } //이미 리스트에 있는지 계속 확인하는거 살짝 효율 아쉬움
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
    BuildDAG(data, query);
    std::map<Vertex, Vertex> M;
    // default : key 값 기준 오름 차순 정렬
    // key가 dag에 있는 값
    // 근데 key 가 중복되면 안되는데 상관 없나,,,? print하면서 비워내면 상관없을 듯
    BackTrack(query, cs, M);
}

void Backtrack::BackTrack(const Graph &query, const CandidateSet &cs, std::map<Vertex, Vertex> &M)
{
    //BackTracking 맡긴다 동섭

    size_t query_size = query.GetNumVertices();

    // https://www.delftstack.com/ko/howto/cpp/how-to-iterate-over-map-in-cpp/ 반복문에 이 코드 참조
    // auto 안쓰고 하는게 더 효율적이냐 호준?
    if (M.size() == query_size)
    {
        // 결과 출력
        std::cout << "a";
        auto iter = M.begin();
        while (iter != M.end())
        {
            std::cout << " " << iter->second;
            iter++;
        }
        std::cout << "\n";
    }

    // 크기 0이면 root부터 시작
    // 일단은 그냥 어거지로 root 변수 넣는데 나중에 root를 전달해줄 방법을 생각해야할 듯? dag 클래스를 파서 root 멤버 변수를 주던가?
    else if (M.size() == 0)
    {
        size_t csize = cs.GetCandidateSize(root);
        for (size_t i = 0; i < csize; i++)
        {
            M.insert(std::pair<Vertex, Vertex>(root, cs.GetCandidate(root, i)));
            // 자식노드가 extendable이면 extendable에 넣어준다.
            for (size_t j = child_start_offset[root]; j < parent_start_offset[root + 1]; j++)
            {
                if (isExtendable(j, M))
                {
                    extendable.push(std::make_pair(cs.GetCandidateSize(j), j));
                }
            }

            visit.insert(cs.GetCandidate(root, i));
            BackTrack(query, cs, M);
            // 이렇게 해도 같은 노드 지워주나,,,? 정신 맑을 때 고민하자
            visit.erase(cs.GetCandidate(root, i));
        }
    }

    else
    {
        // extendable 따지려면 dag의 parent를 알아야한다. how..
        // 이거 알 수 있게 dag다시 짜는게 더 좋을까?
        // 찾아보니까 그렇게 하는게 좋다는 글이 있네
        // 일단은 좀 비효율적이어도 돌아가게 한번 짜본다.
        // 리커시브하게 하다가 i랑 j값 꼬일거 같다 왠지

        Vertex u; //여기에 로직에 맞게 u 넣어준다.
        u = extendable.top().second;
        extendable.pop();

        size_t csize_u = cs.GetCandidateSize(u);
        for (size_t j = 0; j < csize_u; j++)
        {
            Vertex v = cs.GetCandidate(u, j);
            // 여기서 꼬일 것 같음
            if (visit.find(v) == visit.end())
            // visit 에 없다는 것

            {
                M.insert(std::pair<Vertex, Vertex>(u, v));
                // 자기자신은 extendable에서 빼준다.
                for (size_t j = child_start_offset[u]; j < parent_start_offset[u + 1]; j++)
                {
                    if (isExtendable(j, M))
                    {
                        extendable.push(std::make_pair(cs.GetCandidateSize(j), j));
                    }
                }
                visit.insert(v);
                BackTrack(query, cs, M);
                visit.erase(v);
            }
        }
    }
}

bool Backtrack::isExtendable(Vertex u, const std::map<Vertex, Vertex> &M)
{
    for (size_t i = parent_start_offset[u]; i < child_start_offset[u]; i++)
    {
        // parent가 하나라도 Mapping 에 없으면
        if (M.find(i) == M.end())
        {
            return false;
        }
    }
    return true;
}
