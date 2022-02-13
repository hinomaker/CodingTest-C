#include <iostream>
#include <memory.h>
using namespace std;

int main()
{
  int N;
  cin >> N;
  int dp[N + 1];

  memset(dp, 0, sizeof(dp));
  dp[2] = 3;

  for(int idx = 4; idx <= N; idx += 2)
  {
    dp[idx] = dp[idx - 2] * 3 + 2;

    for(int jdx = idx - 4; jdx > 0; jdx -= 2)
      dp[idx] += dp[jdx] * 2;
  }
  cout << dp[N];
}
