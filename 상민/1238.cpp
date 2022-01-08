#include <iostream>
#include <memory.h>
#include <limits.h>
#include <cmath>
using namespace std;

int N, M, X;
int map[1000][1000];

int main()
{
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

  // multiple shortest paths -> floyd-warshall */
  for(int kdx = 0; kdx < N; kdx++)
  {
    for(int idx = 0; idx < N; idx++)
    {
      for(int jdx = 0; jdx < N; jdx++)
        map[idx][jdx] = min(map[idx][jdx], map[idx][kdx] + map[kdx][jdx]);
    }
  }

  int max_time = 0;

  for(int ndx = 0; ndx < N; ndx++)
  {
    max_time = max(max_time, map[ndx][X-1] + map[X-1][ndx]);
  }

  cout << max_time;
}
