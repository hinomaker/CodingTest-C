#include <set>
#include <iostream>
#include <memory.h>
using namespace std;
int N, M;

void dfsearch(int cnt, int lst[]){
  if(cnt == M)
  {
    for(int ldx = 0; ldx < M; ldx++)
      cout << lst[ldx] << " ";
    cout << '\n';
    return;
  }

  for(int idx = 1; idx <= N; idx++){
    lst[cnt] = idx;
    dfsearch(cnt + 1, lst);
  }
}

int main(){
  cin >> N >> M;
  int lst[M];
  dfsearch(0, lst);
}
