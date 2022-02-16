#include <set>
#include <queue>
#include <string>
#include <iostream>
using namespace std;
typedef pair<int, int> cod;

int N, M;
string board[10];
set<pair<cod, cod>> visit;
struct el{cod r; cod b; int cnt;};
cod dir[4] = {{0,1}, {0,-1}, {1,0}, {-1,0}};

pair<bool, cod> move_color(cod xy, int ddx){
  bool flag = false;
  while(xy.first >= 0 && xy.first < N && xy.second >= 0 && xy.second < M && board[xy.first][xy.second] != '#'){
    xy = {xy.first + dir[ddx].first, xy.second + dir[ddx].second};
    if(board[xy.first][xy.second] == 'O'){
      flag = true;
      break;
    }
  }
  if(flag)
    return {flag, xy};
  return {flag, {xy.first - dir[ddx].first, xy.second - dir[ddx].second}};
}

struct el tilt(cod r, cod b, int ddx){
  bool comp;
  if(ddx == 0)
    comp = (r.second > b.second);
  else if(ddx == 1)
    comp = (r.second < b.second);
  else if(ddx == 2)
    comp = (r.first > b.first);
  else
    comp = (r.first < b.first);

  pair<bool, cod> result_r;
  pair<bool, cod> result_b;
  if(comp){
    result_r = move_color(r, ddx);
    if(!result_r.first)
      board[result_r.second.first][result_r.second.second] = '#';
    result_b = move_color(b, ddx);
    if(!result_r.first)
      board[result_r.second.first][result_r.second.second] = '.';
  }
  else{
    result_b = move_color(b, ddx);
    if(!result_b.first)
      board[result_b.second.first][result_b.second.second] = '#';
    result_r = move_color(r, ddx);
    if(!result_b.first)
      board[result_b.second.first][result_b.second.second] = '.';
  }
  return {result_r.second, result_b.second, (result_b.first)? -1 : result_r.first};
}

int bfsearch(cod r, cod b){
  queue<struct el> search;
  search.push({r, b, 0});
  visit.insert({r, b});

  while(!search.empty() && search.front().cnt < 10){
    struct el curr = search.front();
    search.pop();

    for(int ddx = 0; ddx < 4; ddx++){
      struct el next = tilt(curr.r, curr.b, ddx);
      if(next.cnt == 1)
        return curr.cnt + 1;
      if(next.cnt == 0 && visit.find({next.r, next.b}) == visit.end()){
        search.push({next.r, next.b, curr.cnt + 1});
        visit.insert({next.r, next.b});
      }
    }
  }
  return -1;
}

int main(){
  cod r, b;
  cin >> N >> M;

  for(int ndx = 0; ndx < N; ndx++){
    cin >> board[ndx];
    for(int mdx = 0; mdx < M; mdx++){
      if(board[ndx][mdx] == 'R')
        r = {ndx, mdx};
      if(board[ndx][mdx] == 'B')
        b = {ndx, mdx};
    }
  }
  board[r.first][r.second] = '.';
  board[b.first][b.second] = '.';
  cout << bfsearch(r, b);
}
