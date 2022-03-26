#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

int R, C;
int office[8][8];
bool check[8][8];
struct camera{int r; int c; int type;};
vector<struct camera> camlist;
vector<vector<int>> dirlist(8);
int direction_count[5] = {4, 2, 4, 4, 1};
pair<int, int> dir[4] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
int min_result = 64;

void blindspot(){
  memset(check, 0, sizeof(check));
  int result = 0;
  for(int cdx = 0; cdx < camlist.size(); cdx++){
    for(int ddx = 0; ddx < dirlist[cdx].size(); ddx++){
      pair<int, int> curr = {camlist[cdx].r, camlist[cdx].c};
      pair<int, int> toadd = dir[dirlist[cdx][ddx]];
      while(curr.first < R && curr.second < C &&
            curr.first >= 0 && curr.second >= 0 &&
            office[curr.first][curr.second] == 0){
        check[curr.first][curr.second] = true;
        curr = {curr.first + toadd.first, curr.second + toadd.second};
      }
    }
  }

  for(int rdx = 0; rdx < R; rdx++)
    for(int cdx = 0; cdx < C; cdx++)
      result += (check[rdx][cdx] == 0) && (office[rdx][cdx] == 0);

  min_result = (min_result > result)? result : min_result;
}


void dfsearch(int idx){
  if(idx == camlist.size()){
    blindspot();
    return;
  }

  int curr_type = camlist[idx].type;

  if(curr_type == 0){
    for(int ddx = 0; ddx < 4; ddx++){
      dirlist[idx].push_back(ddx);
      dfsearch(idx+1);
      dirlist[idx].clear();
    }
  }
  else if(curr_type == 1){
    for(int ddx = 0; ddx < 2; ddx++){
      dirlist[idx].push_back(ddx);
      dirlist[idx].push_back((ddx + 2) % 4);
      dfsearch(idx+1);
      dirlist[idx].clear();
    }
  }
  else if(curr_type == 2){
    for(int ddx = 0; ddx < 4; ddx++){
      dirlist[idx].push_back(ddx);
      dirlist[idx].push_back((ddx + 1) % 4);
      dfsearch(idx+1);
      dirlist[idx].clear();
    }
  }
  else if(curr_type == 3){
    for(int ddx = 0; ddx < 4; ddx++){
      dirlist[idx].push_back(ddx);
      dirlist[idx].push_back((ddx + 1) % 4);
      dirlist[idx].push_back((ddx + 2) % 4);
      dfsearch(idx+1);
      dirlist[idx].clear();
    }
  }
  else{
    dirlist[idx].push_back(0);
    dirlist[idx].push_back(1);
    dirlist[idx].push_back(2);
    dirlist[idx].push_back(3);
    dfsearch(idx+1);
    dirlist[idx].clear();
  }
}


int main(){
  cin >> R >> C;
  for(int rdx = 0; rdx < R; rdx++){
    for(int cdx = 0; cdx < C; cdx++){
      cin >> office[rdx][cdx];
      if(office[rdx][cdx] != 0 && office[rdx][cdx] != 6){
        camlist.push_back({rdx, cdx, office[rdx][cdx]-1});
        office[rdx][cdx] = 0;
      }
    }
  }

  dfsearch(0);
  cout << min_result;
}
