#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int parent[10001];
struct edge{
  int src;
  int dst;
  int wgt;
};
bool compare(struct edge a, struct edge b){
  return a.wgt < b.wgt;
}

int find_parent(int curr){
  if(curr == parent[curr])
    return curr;

  return find_parent(parent[curr]);
}

bool merge(int a, int b){
  int parent_a = find_parent(a);
  int parent_b = find_parent(b);

  if(parent_a == parent_b)
    return false;

  if(parent_a < parent_b)
    parent[parent_b] = parent_a;
  else
    parent[parent_a] = parent_b;

  return true;
}

int main(){
  int V, E;
  cin >> V >> E;

  vector<struct edge> edgelist;
  int a, b, c;
  ll answer = 0;
  int count = 0;

  for(int edx = 0; edx < E; edx++){
    cin >> a >> b >> c;
    edgelist.push_back({a, b, c});
  }

  for(int vdx = 1; vdx <= V; vdx++)
    parent[vdx] = vdx;

  sort(edgelist.begin(), edgelist.end(), compare);

  for(int edx = 0; edx < E && count < V-1; edx++){
    struct edge curr = edgelist[edx];

    bool success = merge(curr.src, curr.dst);

    if(success){
      answer += curr.wgt;
      count++;
    }
  }

  cout << answer;
}
