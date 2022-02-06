#include <cmath>
#include <tuple>
#include <vector>
#include <iostream>
using namespace std;

int N, K;                                             /* map size, horse num */
pair<int, int> dir[4] = {{0,1},{0,-1},{-1,0},{1,0}};  /* move coordinate */
tuple<int, int, int> plst[10];                        /* piece list with row, col, direction */
int map[12][12];                                      /* map info - white, red, blue */
vector<int> acc[12][12];                              /* map info - piece accumulation */

int opp(int ddx)
{
  return (ddx == 0 || ddx == 2)? (ddx + 1) : (ddx - 1);
}

int main()
{
  cin >> N >> K;

  for(int rdx = 0; rdx < N; rdx++)
  {
    for(int cdx = 0; cdx < N; cdx++)
      cin >> map[rdx][cdx];
  }

  int count = -1;
  int row, col, ddx;
  for(int kdx = 0; kdx < K; kdx++)
  {
    cin >> row >> col >> ddx;
    plst[kdx] = make_tuple(row-1, col-1, ddx - 1);
    acc[row-1][col-1].push_back(kdx);

    if(acc[row-1][col-1].size() >= 4)
    {
      cout << count + 1;
      return 0;
    }
  }

  while(++count <= 1000)
  {
    for(int kdx = 0; kdx < K; kdx++)
    {
      ddx = get<2>(plst[kdx]);
      pair<int, int> curr = {get<0>(plst[kdx]), get<1>(plst[kdx])};
      pair<int, int> next = {curr.first + dir[ddx].first, curr.second + dir[ddx].second};

      if(min(next.first, next.second) < 0 || max(next.first, next.second) >= N || map[next.first][next.second] == 2)
      {
        get<2>(plst[kdx]) = opp(ddx);
        next = {curr.first + dir[opp(ddx)].first, curr.second + dir[opp(ddx)].second};

        if(min(next.first, next.second) < 0 || max(next.first, next.second) >= N || map[next.first][next.second] == 2)
          continue;
      }

      if(map[next.first][next.second] == 1)
      {
        int iter = -1;
        while(iter != kdx)
        {
          iter = acc[curr.first][curr.second].back();
          acc[curr.first][curr.second].pop_back();
          acc[next.first][next.second].push_back(iter);
          get<0>(plst[iter]) = next.first;
          get<1>(plst[iter]) = next.second;
        }
      }

      else
      {
        auto iter = acc[curr.first][curr.second].end();
        do
        {
          get<0>(plst[*(--iter)]) = next.first;
          get<1>(plst[*iter]) = next.second;
        } while((*iter) != kdx);

        acc[next.first][next.second].insert(acc[next.first][next.second].end(), iter, acc[curr.first][curr.second].end());
        acc[curr.first][curr.second].erase(iter, acc[curr.first][curr.second].end());
      }

      if(acc[next.first][next.second].size() >= 4)
      {
        cout << count + 1;
        return 0;
      }
    }
  }
  cout << -1;
}
