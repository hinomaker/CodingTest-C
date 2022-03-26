#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int parent[100]; int N;
struct edge{
  int src;
  int dst;
  double cost;
};

bool compare(struct edge a, struct edge b){
  return a.cost < b.cost;
}

int find_parent(int curr){
  if(curr == parent[curr])
    return curr;

  return find_parent(parent[curr]);
}

bool merge(int idx, int jdx){
  int idx_parent = find_parent(idx);
  int jdx_parent = find_parent(jdx);

  if(idx_parent == jdx_parent)
    return false;

  int new_parent = min(idx_parent, jdx_parent);
  parent[idx_parent] = new_parent;
  parent[jdx_parent] = new_parent;
  return true;
}

int main(){
  cin >> N;
  pair<double, double> star[N];
  for(int ndx = 0; ndx < N; ndx++){
    cin >> star[ndx].first >> star[ndx].second;
  }

  for(int ndx = 0; ndx < N; ndx++){
    parent[ndx] = ndx;
  }

  vector<struct edge> edgelist;
  for(int idx = 0; idx < N; idx++)
    for(int jdx = idx + 1; jdx < N; jdx++)
      edgelist.push_back({idx, jdx, (star[idx].first - star[jdx].first) * (star[idx].first - star[jdx].first) + (star[idx].second - star[jdx].second) * (star[idx].second - star[jdx].second)});

  sort(edgelist.begin(), edgelist.end(), compare);

  int count = 0;
  double result = 0;
  for(int edx = 0; edx < edgelist.size() && count < N-1; edx++){
    struct edge curr = edgelist[edx];
    bool success = merge(curr.src, curr.dst);

    if(success){
      count++;
      result += (sqrt(curr.cost));
    }
  }
  cout << fixed;
  cout.precision(2);
  cout << result;
}
