#include <iostream>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define endl '\n'
#define ll long long 

int N, M;
int arr[1001][1001];
int dp[1001][1001];

void solution()
{
   dp[1][1] = arr[1][1];

    for(int i=1; i<=N; i++) dp[1][i] = arr[1][i];
    for(int i=1; i<=M; i++) dp[i][1] = arr[i][1];

    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=M; j++)
        {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + arr[i][j];
        }
    }
    

    cout << dp[N][M] << endl;
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);

   cin >> N >> M;

   for(int i=1; i<=N; i++)
    for(int j=1; j<=M; j++)
        cin >> arr[i][j];

   solution();
}
