#include <iostream>
using namespace std;
typedef pair<int, int> cod;
int dice[6] = {0, 0, 0, 0, 0, 0};

void dice_move(int move)
{
  int d = dice[0]; int t = dice[1];
  int f = dice[2]; int r = dice[3];
  int e = dice[4]; int w = dice[5];

  if(move == 0){
    dice[0] = e; dice[1] = w; dice[4] = t; dice[5] = d;
  }
  else if(move == 1){
    dice[0] = w; dice[1] = e; dice[4] = d; dice[5] = t;
  }
  else if(move == 2){
    dice[0] = r; dice[1] = f; dice[2] = d; dice[3] = t;
  }
  else{
    dice[0] = f; dice[1] = r; dice[2] = t; dice[3] = d;
  }
}

int main(){
  int N, M, K, x, y, ddx;
  cin >> N >> M >> x >> y >> K;
  int map[20][20];
  cod dir[4] = {{0,1}, {0,-1}, {-1,0}, {1,0}};

  for(int ndx = 0; ndx < N; ndx++)
    for(int mdx = 0; mdx < M; mdx++)
      cin >> map[ndx][mdx];

  cod curr = {x, y};
  for(int kdx = 0; kdx < K; kdx++){
    cin >> ddx;
    cod next = {curr.first + dir[ddx-1].first, curr.second + dir[ddx-1].second};
    if(next.first < 0 || next.second < 0 || next.first >= N || next.second >= M)
      continue;

    curr = next;
    dice_move(ddx - 1);

    if(map[curr.first][curr.second] == 0)
      map[curr.first][curr.second] = dice[0];
    else{
      dice[0] = map[curr.first][curr.second];
      map[curr.first][curr.second] = 0;
    }

    cout << dice[1] << endl;
  }
}
