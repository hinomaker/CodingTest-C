#include <iostream>
#include <string>
#include <memory.h>
using namespace std;
bool wheel[4][8];
int idx[4];

void rotate(int wdx, int dir, bool left, bool right){
  if(left && wdx > 0)
    if(wheel[wdx][(6 + idx[wdx]) % 8] != wheel[wdx-1][(2 + idx[wdx-1]) % 8])
      rotate(wdx-1, -dir, true, false);

  if(right && wdx < 3)
    if(wheel[wdx][(2 + idx[wdx]) % 8] != wheel[wdx+1][(6 + idx[wdx+1]) % 8])
      rotate(wdx+1, -dir, false, true);

  idx[wdx] = (idx[wdx] - dir + 8) % 8;
}

int main(){
  string input;
  memset(idx, 0, sizeof(idx));

  for(int wdx = 0; wdx < 4; wdx++){
    cin >> input;
    for(int iter = 0; iter < 8; iter++)
      wheel[wdx][iter] = (input[iter] == '1');
  }

  int count, num, dir;
  cin >> count;
  for(int cdx = 0; cdx < count; cdx++){
    cin >> num >> dir;
    rotate(num-1, dir, true, true);
  }

  cout << (wheel[0][idx[0]] == 1) + (wheel[1][idx[1]] == 1) * 2 +
          (wheel[2][idx[2]] == 1) * 4 + (wheel[3][idx[3]] == 1) * 8;
}
