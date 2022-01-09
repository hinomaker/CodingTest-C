/* solved by dijkstra algorithm */

#include <iostream>
#include <queue>
#include <cmath>
#include <memory.h>
using namespace std;
typedef pair<int, int> cod;

/* compare function for priority_queue */
struct compare
{
  bool operator()(cod a, cod b)
  {
    return a.second > b.second;
  }
};


int N, K;
priority_queue<cod, vector<cod>, compare> search;

int dist[100001];

int main()
{
  /* initialize to INF */
  memset(dist, 0x3f, sizeof(dist));
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  cin >> N >> K;

  /* if N larger than K, dijkstra not required */
  if(N >= K)
  {
    cout << N-K;
    return 0;
  }

  search.push({N, 0});
  dist[N] == 0;
  /* dijkstra */
  while(!search.empty())
  {
    cod curr = search.top();
    search.pop();

    if(curr.first == K)
      break;

    if(curr.second > dist[curr.first])
      continue;

    if(curr.first < 100000 && dist[curr.first + 1] > curr.second + 1)
    {
      dist[curr.first + 1] = curr.second + 1;
      search.push({curr.first + 1, dist[curr.first + 1]});
    }

    if(curr.first > 0 && dist[curr.first - 1] > curr.second + 1)
    {
      dist[curr.first - 1] = curr.second + 1;
      search.push({curr.first - 1, dist[curr.first - 1]});
    }

    if(curr.first <= 50000 && dist[curr.first * 2] > curr.second)
    {
      dist[curr.first * 2] = curr.second;
      search.push({curr.first * 2, dist[curr.first * 2]});
    }
  }

  cout << dist[K];
}
