#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;
typedef pair<int, int> cod;

int N, M;
int map[8][8];
bool visit[8][8];
vector<cod> wall;
cod dir[4] = {{1,0},{-1,0},{0,1},{0,-1}};
queue<cod> bfs;

int corona(int idx, int jdx, int kdx){
  int area = 0;
  memset(visit, 0, sizeof(visit));

  for(int ndx = 0; ndx < N; ndx++){
    for(int mdx = 0; mdx < M; mdx++){
      if(visit[ndx][mdx] || map[ndx][mdx] == 1 || map[ndx][mdx] == 2)
        continue;

      bfs.push({ndx, mdx});
      visit[ndx][mdx] = true;
      int cnt = 0;
      bool flag = true;

      while(!bfs.empty()){
        cod curr = bfs.front();
        bfs.pop();
        cnt++;

        for(int ddx = 0; ddx < 4; ddx++){
          cod next = {curr.first + dir[ddx].first, curr.second + dir[ddx].second};
          if(next.first < 0 || next.second < 0 || next.first >= N || next.second >= M)
            continue;
          if(visit[next.first][next.second] || map[next.first][next.second] == 1)
            continue;

          bfs.push(next);
          visit[next.first][next.second] = true;

          if(map[next.first][next.second] == 2)
            flag = false;
        }
      }
      if(flag)
        area += cnt;
    }
  }
  return area;
}



int main(){
  cin >> N >> M;
  int answer = 0;

  for(int ndx = 0; ndx < N; ndx++){
    for(int mdx = 0; mdx < M; mdx++){
      cin >> map[ndx][mdx];

      if(map[ndx][mdx] == 0)
        wall.push_back({ndx, mdx});
    }
  }

  for(int idx = 0; idx < wall.size(); idx++){
    for(int jdx = idx + 1; jdx < wall.size(); jdx++){
      for(int kdx = jdx + 1; kdx < wall.size(); kdx++){
        map[wall[idx].first][wall[idx].second] = 1;
        map[wall[jdx].first][wall[jdx].second] = 1;
        map[wall[kdx].first][wall[kdx].second] = 1;

        answer = max(answer, corona(idx, jdx, kdx));

        map[wall[idx].first][wall[idx].second] = 0;
        map[wall[jdx].first][wall[jdx].second] = 0;
        map[wall[kdx].first][wall[kdx].second] = 0;

      }
    }
  }
  cout << answer;

}
