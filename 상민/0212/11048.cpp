#include <iostream>
#include <memory.h>
using namespace std;

int main()
{
  int N, M;
  cin >> N >> M;
  int candy[N + 1][M + 1];
  memset(candy, 0, sizeof(candy));

  for(int rdx = 1; rdx <= N; rdx++)
    for(int cdx = 1; cdx <= M; cdx++)
      cin >> candy[rdx][cdx];

  for(int rdx = 1; rdx <= N; rdx++)
    for(int cdx = 1; cdx <= M; cdx++)
      candy[rdx][cdx] += max(candy[rdx-1][cdx], candy[rdx][cdx-1]);

  cout << candy[N][M];
}
