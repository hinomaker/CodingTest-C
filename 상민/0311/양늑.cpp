#include <string>
#include <vector>
#include <set>
using namespace std;
int max_sheep = 0;

/*
  int node : current node number
  vec<vec> edgeset : rearranged edge info
  set visit : node numbers to check
  int w : current wolf number
  int s : current sheep number
*/
void dfsearch(int node, vector<vector<int>> edgeset, vector<int> info, set<int> visit, int w, int s)
{
  int curr_w = info[node] + w;
  int curr_s = 1 - info[node] + s;

  if(curr_w >= curr_s)
    return;

  visit.erase(node);
  for(int edx = 0; edx < edgeset[node].size(); edx++)
    visit.insert(edgeset[node][edx]);

  for(auto iter = visit.begin(); iter != visit.end(); iter++)
    dfsearch(*iter, edgeset, info, visit, curr_w, curr_s);

  max_sheep = max(max_sheep, curr_s);
}

int solution(vector<int> info, vector<vector<int>> edges)
{
    int answer = 0;

    vector<vector<int>> edgeset(info.size(), vector<int>(0));
    for(int edx = 0; edx < edges.size(); edx++)
      edgeset[edges[edx][0]].push_back(edges[edx][1]);

    set<int> visit = {0};
    dfsearch(0, edgeset, info, visit, 0, 0);

    return max_sheep;
}
