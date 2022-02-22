#include <vector>
#include <iostream>
#include <memory.h>
using namespace std;

vector<vector<int>> edge(100);
bool visit[100];
int cnt = -1;

void dfsearch(int node){
  cnt++;
  visit[node] = true;

  for(int ndx = 0; ndx < edge[node].size(); ndx++){
    if(!visit[edge[node][ndx]])
      dfsearch(edge[node][ndx]);
  }
}


int main(){
  int N, E;
  cin >> N >> E;

  int src, dst;
  for(int edx = 0; edx < E; edx++){
    cin >> src >> dst;
    edge[src-1].push_back(dst-1);
    edge[dst-1].push_back(src-1);
  }

  memset(visit, 0, sizeof(visit));
  dfsearch(0);

  cout << cnt;

}
