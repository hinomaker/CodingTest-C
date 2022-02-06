#include <set>
#include <queue>
#include <string>
#include <memory.h>
#include <iostream>

using namespace std;
string field[12];
char puyo[5] = {'R', 'G', 'B', 'P', 'Y'};
pair<int, int> dir[4] = {{0,1},{0,-1},{-1,0},{1,0}};
bool visit[12][6];
queue<pair<int, int>> search;
set<pair<int, int>> waitlist;

int main()
{
  for(int rdx = 0; rdx < 12; rdx++)
    cin >> field[rdx];

  int cnt = -1;
  bool explode = true;

  while(explode)
  {
    explode = false;
    cnt++;

    for(int rdx = 0; rdx < 12; rdx++)
    {
      for(int cdx = 0; cdx < 6; cdx++)
      {
        if(field[rdx][cdx] == '.')
          continue;

        char color = field[rdx][cdx];
        memset(visit, 0, sizeof(visit));
        search.push({rdx, cdx});
        waitlist.insert({rdx, cdx});
        visit[rdx][cdx] = true;

        while(!search.empty())
        {
          pair<int, int> curr = search.front();
          search.pop();

          for(int ddx = 0; ddx < 4; ddx++)
          {
            pair<int, int> next = {curr.first + dir[ddx].first, curr.second + dir[ddx].second};

            if(next.first < 0 || next.second < 0 || next.first >= 12 || next.second >= 6)
              continue;
            if(visit[next.first][next.second] || field[next.first][next.second] != color)
              continue;

            search.push(next);
            visit[next.first][next.second] = true;
            waitlist.insert(next);
          }
        }

        if(waitlist.size() >= 4)
        {
          explode = true;
          for(auto iter = waitlist.begin(); iter != waitlist.end(); iter++)
            field[(*iter).first][(*iter).second] = '.';
        }
        waitlist.clear();
      }
    }

    for(int cdx = 0; cdx < 6; cdx++)
    {
      int ptr = 11;
      for(int rdx = 11; rdx >= 0; rdx--)
      {
        if(field[rdx][cdx] == '.')
          continue;
        field[ptr--][cdx] = field[rdx][cdx];
      }
      for(; ptr >= 0; ptr--)
        field[ptr][cdx] = '.';
    }
  }

  cout << cnt;
}
