#include <iostream>
#include <queue>
#include <memory.h>
#include <limits.h>
using namespace std;

int N;
int rain[100][100];
int rain_max = 0;
bool visit[100][100];
queue<pair<int, int>> search;
pair<int, int> dir[4] = {{1,0}, {0,1}, {-1,0}, {0,-1}};

int safe_count(int sink){
  memset(visit, 0, sizeof(visit));
  int result = 0;
  for(int rdx = 0; rdx < N; rdx++){
    for(int cdx = 0; cdx < N; cdx++){
      if(visit[rdx][cdx] || rain[rdx][cdx] <= sink)
        continue;
      search.push({rdx, cdx});
      visit[rdx][cdx] = 1;
      while(!search.empty()){
        pair<int, int> curr = search.front();
        search.pop();
        for(int ddx = 0; ddx < 4; ddx++){
          pair<int, int> next = {curr.first + dir[ddx].first, curr.second + dir[ddx].second};
          if(next.first < 0 || next.second < 0 || next.first >= N || next.second >= N)
            continue;
          if(visit[next.first][next.second] || rain[next.first][next.second] <= sink)
            continue;
          search.push({next.first, next.second});
          visit[next.first][next.second] = 1;
        }
      }
      result++;
    }
  }
  return result;
}

int main(){
  cin >> N;
  for(int rdx = 0; rdx < N; rdx++){
    for(int cdx = 0; cdx < N; cdx++){
      cin >> rain[rdx][cdx];
      rain_max = max(rain_max, rain[rdx][cdx]);
    }
  }

  int answer = 1;
  for(int idx = 1; idx < rain_max; idx++)
    answer = max(answer, safe_count(idx));
  cout << answer;
}
