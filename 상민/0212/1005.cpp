#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;


void dfsearch(int build, bool visit[], int totalt[], vector<vector<int>> &relation, int btime[])
{
  if(relation[build].size() == 0)
  {
    totalt[build] = btime[build];
    visit[build] = true;
    return;
  }

  int time_max = 0;
  for(int idx = 0; idx < relation[build].size(); idx++)
  {
    if(!visit[relation[build][idx]])
      dfsearch(relation[build][idx], visit, totalt, relation, btime);

    time_max = max(time_max, totalt[relation[build][idx]]);
  }

  totalt[build] = time_max + btime[build];
  visit[build] = true;
  return;
}

int main()
{
  int T, N, K, src, dst, build;
  int btime[1000];
  bool visit[1000];
  int totalt[1000];
  cin >> T;

  for(int tdx = 0; tdx < T; tdx++)
  {
    memset(visit, 0, sizeof(visit));
    memset(totalt, 0, sizeof(totalt));

    cin >> N >> K;
    for(int idx = 0; idx < N; idx++)
      cin >> btime[idx];

    vector<vector<int>> relation(N);
    for(int idx = 0; idx < K; idx++)
    {
      cin >> src >> dst;
      relation[dst-1].push_back(src-1);
    }

    cin >> build;
    dfsearch(build-1, visit, totalt, relation, btime);
    cout << totalt[build-1] << '\n';
  }
}
