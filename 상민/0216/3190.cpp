#include <iostream>
#include <deque>
#include <memory.h>
using namespace std;
typedef pair<int, int> cod;
cod dir[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int main(){
  int N, K, L;
  cin >> N >> K;
  bool snake[N][N];
  bool apple[N][N];
  memset(snake, 0, sizeof(snake));
  memset(apple, 0, sizeof(apple));

  int row, col;
  for(int kdx = 0; kdx < K; kdx++){
    cin >> row >> col;
    apple[row-1][col-1] = true;
  }

  cin >> L;
  cod move[L];
  int time, ddx, ldx;
  for(ldx = 0; ldx < L; ldx++){
    char tmp;
    cin >> time >> tmp;
    move[ldx] = {time, (tmp == 'D')? 1: -1};
  }

  snake[0][0] = true;
  ddx = 0; ldx = 0;
  deque<cod> trace = {{0,0}};

  for(time = 1; ; time++){
    cod head = {trace.back().first + dir[ddx].first, trace.back().second + dir[ddx].second};
    if(min(head.first, head.second) < 0 || max(head.first, head.second) >= N || snake[head.first][head.second]){
      break;
    }
    snake[head.first][head.second] = true;
    trace.push_back(head);

    if(apple[head.first][head.second])
      apple[head.first][head.second] = false;
    else{
      snake[trace.front().first][trace.front().second] = false;
      trace.pop_front();
    }

    if(ldx < L && move[ldx].first == time){
      ddx = (ddx + move[ldx].second + 4) % 4;
      ldx++;
    }
  }
  cout << time;
}
