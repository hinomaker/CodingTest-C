/* solved by dijkstra algorithm */

#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;
typedef pair<int, int> cod;

/* struct for saving row, column, roupie values */
struct el
{
  int r;
  int c;
  int rp;
};

/* compare function for priority_queue */
struct compare
{
  bool operator()(struct el a, struct el b)
  {
    return a.rp > b.rp;
  }
};

int N;
int dist[125][125];                                             // array for shortest path length
int cave[125][125];                                             // array for edge weights: lost roupie
priority_queue<struct el, vector<struct el>, compare> search;   // array for dijkstra search
cod dir[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};                // array for unit move


int main()
{
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  int test_cnt = 1;

  while(true)
  {
    cin >> N;
    if(N == 0)
      break;
    /* initialize to INF */
    memset(dist, 0x3f, sizeof(dist));

    for(int rdx = 0; rdx < N; rdx++)
    {
      for(int cdx = 0; cdx < N; cdx++)
        cin >> cave[rdx][cdx];
    }

    search.push({0, 0, cave[0][0]});
    dist[0][0] = cave[0][0];

    /* dijkstra */
    while(!search.empty())
    {
      struct el curr = search.top();
      search.pop();

      if(curr.r == N-1 && curr.c == N-1)
        break;

      if(curr.rp > dist[curr.r][curr.c])
        continue;

      for(int ddx = 0; ddx < 4; ddx++)
      {
        struct el next;
        next.r = curr.r + dir[ddx].first;
        next.c = curr.c + dir[ddx].second;

        if(next.r < 0 || next.c < 0 || next.r >= N || next.c >= N)
          continue;

        int cal_rp = curr.rp + cave[next.r][next.c];

        if(cal_rp < dist[next.r][next.c])
        {
          next.rp = cal_rp;
          search.push(next);
          dist[next.r][next.c] = cal_rp;
        }
      }
    }
    /* get rid of left members in queue */
    while(!search.empty())
      search.pop();

    cout << "Problem " << test_cnt << ": " << dist[N-1][N-1] << '\n';

    test_cnt++;
  }
}
