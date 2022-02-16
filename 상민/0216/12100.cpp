#include <iostream>
#include <memory.h>
#include <algorithm>
using namespace std;
typedef pair<int, int> cod;

int N;
int answer = 0;
int board[25][25];
bool mrge[25][25];
cod dir[4] = {{0,1}, {0,-1}, {1,0}, {-1,0}};

void dfsearch(int cnt, int ddx){
  if(cnt == 5){
    for(int rdx = 0; rdx < N; rdx++)
      for(int cdx = 0; cdx < N; cdx++)
        answer = max(answer, board[rdx][cdx]);
    return;
  }

  int temp[25][25];
  copy(&board[0][0], &board[0][0] + 625, &temp[0][0]);
  memset(mrge, 0, sizeof(mrge));

  if(ddx / 2 == 0){
    for(int cdx = 0; cdx < N; cdx++){
      int ptr = (ddx == 0)? 0: N-1;
      int rdx = (ddx == 0)? 1: N-2;
      for(; rdx >= 0 && rdx < N; rdx += dir[ddx].second){
        if(board[rdx][cdx] == 0)
          continue;
        if(board[rdx][cdx] == board[ptr][cdx] && mrge[ptr][cdx] == false){
          board[ptr][cdx] *= 2;
          mrge[ptr][cdx] = true;
        }else if(board[ptr][cdx] == 0)
          board[ptr][cdx] = board[rdx][cdx];
        else{
          ptr += dir[ddx].second;
          board[ptr][cdx] = board[rdx][cdx];
        }
      }
      for(ptr += dir[ddx].second; ptr >= 0 && ptr < N; ptr += dir[ddx].second)
        board[ptr][cdx] = 0;
    }
  }else{
    for(int rdx = 0; rdx < N; rdx++){
      int ptr = (ddx == 2)? 0: N-1;
      int cdx = (ddx == 2)? 1: N-2;
      for(; cdx >= 0 && cdx < N; cdx += dir[ddx].first){
        if(board[rdx][cdx] == 0)
          continue;
        if(board[rdx][cdx] == board[rdx][ptr] && mrge[rdx][ptr] == false){
          board[rdx][ptr] *= 2;
          mrge[rdx][ptr] = true;
        }else if(board[rdx][ptr] == 0)
          board[rdx][ptr] = board[rdx][cdx];
        else{
          ptr += dir[ddx].first;
          board[rdx][ptr] = board[rdx][cdx];
        }
      }
      for(ptr += dir[ddx].first; ptr >= 0 && ptr < N; ptr += dir[ddx].first)
        board[rdx][ptr] = 0;
    }
  }

  for(int dddx = 0; dddx < 4; dddx++){
    dfsearch(cnt + 1, dddx);
  }
  copy(&temp[0][0], &temp[0][0] + 625, &board[0][0]);
}

int main(){
  cin >> N;

  for(int i=0;i<N;i++)
      for(int j=0;j<N;j++)
          cin >> board[i][j];

  for(int ddx = 0; ddx < 4; ddx++)
    dfsearch(0, ddx);

  cout << answer;
}
