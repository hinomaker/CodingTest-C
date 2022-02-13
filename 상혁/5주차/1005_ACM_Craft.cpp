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

int T, N, K, target;
int answer[1001];
int arr[1001];
vector<int> vec[1001];
bool visited[1001];

void dfs(int from)
{
    visited[from] = true;
    if(vec[from].size() == 0)
    {
        answer[from] = arr[from];
        return;
    }

    int mx = 0;
    for(int i=0; i<vec[from].size(); i++)
    {
        if(!visited[vec[from][i]]) dfs(vec[from][i]);
        
        mx = max(mx, answer[vec[from][i]]);
    }

    answer[from] = mx + arr[from];
    return;
}

void solution()
{
    dfs(target);

    cout << answer[target] << endl;
}

void clear()
{
    for(int i=1; i<=N; i++) 
    {
        arr[i] = 0;
        vec[i].clear();
        visited[i] = false;
        answer[i] = 0;
    }
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);

   cin >> T;

   for(int i=0; i<T; i++)
   {
        cin >> N >> K;

        clear();

        for(int j=1; j<=N; j++)
        {
            cin >> arr[j];
        }

        for(int j=0; j<K; j++)
        {
            int from, to;
            cin >> from >> to;
            vec[to].push_back(from);
        }

        cin >> target;

        solution();
    }

}
