#include <set>
#include <iostream>
#include <memory.h>
using namespace std;
int N, M;
bool visit[9];

void dfsearch(int cnt, int lst[]){
  if(cnt == M)
  {
    for(int ldx = 0; ldx < M; ldx++)
      cout << lst[ldx] << " ";
    cout << '\n';
    return;
  }

  for(int idx = 1; idx <= N; idx++){
    if(!visit[idx]){
      visit[idx] = true;
      lst[cnt] = idx;
      dfsearch(cnt + 1, lst);
      visit[idx] = false;
    }
  }
}

int main(){
  cin >> N >> M;
  memset(visit, 0, sizeof(visit));
  int lst[M];
  dfsearch(0, lst);
}
