#include <iostream>
using namespace std;

int main(){
  int time[17] = {0,};
  int pay[17] = {0,};
  int N;

  cin >> N;
  for(int idx = 1; idx <= N; idx++)
    cin >> time[idx] >> pay[idx];

  for(int idx = N; idx >= 1; idx--){
    if(idx + time[idx] > N + 1)
      pay[idx] = pay[idx + 1];
    else
      pay[idx] = max(pay[idx + 1], pay[idx] + pay[idx + time[idx]]);
  }
    cout << pay[1];
}
