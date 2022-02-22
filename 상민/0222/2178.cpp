#include <iostream>
#include <string>
#include <memory.h>
#include <queue>
using namespace std;
typedef pair<int, int> cod;

int N, M;
string miro[100];
bool visit[100][100];
cod dir[4] = {{1,0},{0,1},{-1,0},{0,-1}};

int main(){
  cin >> N >> M;

  for(int ndx = 0; ndx < N; ndx++)
    cin >> miro[ndx];

  queue<pair<cod, int>> bfsearch;
  memset(visit, 0, sizeof(visit));
  bfsearch.push({{0,0},1});
  visit[0][0] = true;

  while(!bfsearch.empty()){
    pair<cod, int> curr = bfsearch.front();
    bfsearch.pop();

    if(curr.first.first == N-1 && curr.first.second == M-1){
      cout << curr.second;
      return 0;
    }

    for(int ddx = 0; ddx < 4; ddx++){
      cod next = {curr.first.first + dir[ddx].first, curr.first.second + dir[ddx].second};

      if(next.first < 0 || next.second < 0 || next.first >= N || next.second >= M)
        continue;

      if(visit[next.first][next.second] || miro[next.first][next.second] == '0')
        continue;

      bfsearch.push({next, curr.second + 1});
      visit[next.first][next.second] = true;
    }
  }
}
