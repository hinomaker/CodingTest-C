#include <iostream>
#include <queue>
#include <cmath>
#include <memory.h>
using namespace std;
typedef pair<int, int> el;

struct compare
{
  bool operator()(el a, el b)
  {
    if(a.second == b.second)
      return a.first > b.first;

    return a.second > b.second;
  }
};

int N, K;
priority_queue<el, vector<el>, compare> search;

bool visit[100001];

int main()
{
  memset(visit, 0, sizeof(visit));
  cin >> N >> K;

  if(N >= K)
  {
    cout << N-K;
    return 0;
  }

  search.push({N, 0});
  visit[N] = true;


  while(!search.empty())
  {
    el curr = search.top();
    search.pop();

    if(curr.first == K)
    {
      cout << curr.second;
      break;
    }

    if(curr.first <= 50000 && !visit[curr.first * 2])
    {
      visit[curr.first * 2] = true;
      search.push({curr.first * 2, curr.second});
    }

    if(curr.first < 100000 && !visit[curr.first + 1])
    {
      visit[curr.first + 1] = true;
      search.push({curr.first + 1, curr.second + 1});
    }

    if(curr.first > 0 && !visit[curr.first - 1])
    {
      visit[curr.first - 1] = true;
      search.push({curr.first - 1, curr.second + 1});
    }

  }
}
