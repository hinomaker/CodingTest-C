/* solved by dijkstra algorithm */

#include <iostream>
#include <memory.h>
#include <cmath>
#include <queue>

using namespace std;
typedef pair<int, int> el;

/* compare function for priority_queue */
struct compare
{
  bool operator()(el a, el b)
  {
    return a.first > b.first;
  }
};

int N, M, X;
int map[1000][1000];                              // array for edge weights
int dist[1000];                                   // array for shortest path length
priority_queue<el, vector<el>, compare> search;   // priority_queue for dijkstra

int main()
{
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  /* initialize to INF */
  memset(map, 0x3f, sizeof(map));
  cin >> N >> M >> X;

  for(int mdx = 0; mdx < M; mdx++)
  {
    int src, dst, len;
    cin >> src >> dst >> len;
    map[src-1][dst-1] = len;
  }

  for(int rdx = 0; rdx < N; rdx++)
    map[rdx][rdx] = 0;

  int max_time = 0;

  for(int ndx = 0; ndx < N; ndx++)
  {
    /* ndx -> X-1 : push ndx */
    search.push({0, ndx});
    memset(dist, 0x3f, sizeof(int) * N);
    dist[ndx] = 0;
    /* dijkstra */
    while(!search.empty())
    {
      el curr = search.top();
      search.pop();

      if(curr.second == X-1)
        break;

      if(curr.first > dist[curr.second])
        continue;

      for(int mdx = 0; mdx < N; mdx++)
      {
        if(map[curr.second][mdx] + curr.first < dist[mdx])
        {
          dist[mdx] = map[curr.second][mdx] + curr.first;
          search.push({dist[mdx], mdx});
        }
      }
    }

    while(!search.empty())
      search.pop();

    int a = dist[X-1];

    /* X-1 -> ndx: push X-1 */
    search.push({0, X-1});
    memset(dist, 0x3f, sizeof(int) * N);
    dist[X-1] = 0;
    /* dijkstra */
    while(!search.empty())
    {
      el curr = search.top();
      search.pop();

      if(curr.second == ndx)
        break;

      if(curr.first > dist[curr.second])
        continue;

      for(int mdx = 0; mdx < N; mdx++)
      {
        if(map[curr.second][mdx] + curr.first < dist[mdx])
        {
          dist[mdx] = map[curr.second][mdx] + curr.first;
          search.push({dist[mdx], mdx});
        }
      }
    }

    while(!search.empty())
      search.pop();

    int b = dist[ndx];

    /* add two shortest length path, update max_time */
    max_time = max(a+b, max_time);
  }

  cout << max_time;
}
