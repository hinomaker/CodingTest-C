#include <iostream>
#include <limits.h>
using namespace std;

int N;
int op_count[4];
int input[11];
int max_val, min_val;

void dfsearch(int idx, int value){
  if(idx == N){
    max_val = max(max_val, value);
    min_val = min(min_val, value);
    return;
  }

  for(int odx = 0; odx < 4; odx++){
    int next_val;
    if(op_count[odx] != 0){
      switch(odx){
        case 0:
          next_val = value + input[idx];
          break;
        case 1:
          next_val = value - input[idx];
          break;
        case 2:
          next_val = value * input[idx];
          break;
        case 3:
          next_val = value / input[idx];
          break;
      }

      op_count[odx]--;
      dfsearch(idx + 1, next_val);
      op_count[odx]++;
    }
  }
}

int main(){
  cin >> N;
  for(int ndx = 0; ndx < N; ndx++)
    cin >> input[ndx];

  for(int odx = 0; odx < 4; odx++)
    cin >> op_count[odx];

  max_val = INT_MIN;
  min_val = INT_MAX;

  dfsearch(1, input[0]);

  cout << max_val << '\n' << min_val;

}
