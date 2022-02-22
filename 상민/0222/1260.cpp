#include <iostream>
#include <memory.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, V;
vector<vector<int>> edge(1000);
bool visit[1000];

void dfsearch(int node){
  cout << node+1 << " ";
  visit[node] = true;

  for(int ndx = 0; ndx < edge[node].size(); ndx++){
    if(!visit[edge[node][ndx]])
      dfsearch(edge[node][ndx]);
  }
}

void bfsearch(int node){
  queue<int> bfs;
  bfs.push(node);
  visit[node] = true;

  while(!bfs.empty()){
    int curr = bfs.front();
    bfs.pop();
    cout << curr + 1 << " ";

    for(int ndx = 0; ndx < edge[curr].size(); ndx++){
      if(!visit[edge[curr][ndx]]){
        bfs.push(edge[curr][ndx]);
        visit[edge[curr][ndx]] = true;
      }
    }
  }
}

int main(){
  cin >> N >> M >> V;

  int src, dst;
  for(int mdx = 0; mdx < M; mdx++){
    cin >> src >> dst;
    edge[src-1].push_back(dst-1);
    edge[dst-1].push_back(src-1);
  }

  for(int ndx = 0; ndx < N; ndx++)
    sort(edge[ndx].begin(), edge[ndx].end());

  memset(visit, 0, sizeof(visit));
  dfsearch(V-1);
  cout << '\n';
  memset(visit, 0, sizeof(visit));
  bfsearch(V-1);
}
