#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;
typedef pair<int, int> cod;

int visit[125][125];
struct compare
{
  bool operator()(cod a, cod b)
  {
    return visit[a.first][a.second] > visit[b.first][b.second];
  }
};

int main()
{
  int N;
  int cave[125][125];
  priority_queue<cod, vector<cod>, compare> search;
  cod dir[4] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
  int test_cnt = 1;

  while(true)
  {
    cin >> N;
    if(N == 0) break;

    memset(visit, -1, sizeof(visit));

    for(int rdx = 0; rdx < N; rdx++)
    {
      for(int cdx = 0; cdx < N; cdx++)
        cin >> cave[rdx][cdx];
    }

    search.push({0, 0});
    visit[0][0] = cave[0][0];

    while(!search.empty())
    {
      cod curr = search.top();
      search.pop();

      if(curr.first == N-1 && curr.second == N-1)
        continue;

      for(int ddx = 0; ddx < 4; ddx++)
      {
        cod next = {curr.first + dir[ddx].first, curr.second + dir[ddx].second};

        if(next.first < 0 || next.second < 0 || next.first >= N || next.second >= N)
          continue;

        int next_rp = cave[next.first][next.second] + visit[curr.first][curr.second];
        if(visit[next.first][next.second] < 0 || visit[next.first][next.second] > next_rp)
        {
          visit[next.first][next.second] = next_rp;
          search.push(next);
        }
      }
    }

    cout << "Problem " << test_cnt << ": " << visit[N-1][N-1] << '\n';


    test_cnt++;

  }
}
