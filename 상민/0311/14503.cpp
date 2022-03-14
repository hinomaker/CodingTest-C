#include <iostream>
#include <memory.h>
using namespace std;

int N, M;
int robot_r, robot_c, robot_d;
bool visit[50][50];
bool walls[50][50];
pair<int, int> dir[4] = {{-1,0}, {0,1}, {1,0}, {0,-1}};

int main(){
  int answer = 0;
  memset(visit, 0, sizeof(visit));
  cin >> N >> M;
  cin >> robot_r >> robot_c >> robot_d;

  for(int rdx = 0; rdx < N; rdx++)
    for(int cdx = 0; cdx < M; cdx++)
      cin >> walls[rdx][cdx];

  pair<int, int> curr = {robot_r, robot_c};
  bool flag = true;

  while(true){
    flag = false;
    if(!visit[curr.first][curr.second]){
      visit[curr.first][curr.second] = true;
      answer++;
    }

    int loop_cnt = 0;
    for(int ddx = (robot_d + 3) % 4; loop_cnt < 4; ddx = (ddx + 3) % 4){
      pair<int, int> next = {curr.first + dir[ddx].first, curr.second + dir[ddx].second};
      loop_cnt++;

      if(next.first < 0 || next.second < 0 || next.first >= N || next.second >= M)
        continue;

      if(walls[next.first][next.second])
        continue;

      if(!visit[next.first][next.second]){
        robot_d = ddx;
        curr = next;
        flag = true;
        break;
      }
    }

    if(!flag){
      int ddx = (robot_d + 2) % 4;
      pair<int, int> next = {curr.first + dir[ddx].first, curr.second + dir[ddx].second};

      if(next.first < 0 || next.second < 0 || next.first >= N || next.second >= M)
        break;

      if(walls[next.first][next.second])
        break;

      curr = next;
    }
  }

  cout << answer;
}
