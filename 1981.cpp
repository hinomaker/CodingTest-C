#include <iostream>
#include <queue>
#include <memory.h>
#include <cmath>

using namespace std;
typedef pair<int, int> cod;

int n;
int table[100][100];
bool visit[100][100];
queue<cod> search;
cod dir[4] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

/* returns possibility of bfs search on the range of [min, max] */
bool bfsearch(int min, int max)
{
  memset(visit, 0, sizeof(visit));
  visit[0][0] = 1;

  if(table[0][0] < min || table[0][0] > max)
    return false;

  search.push({0,0});

  while(!search.empty())
  {
    cod curr = search.front();
    search.pop();

    for(int ddx = 0; ddx < 4; ddx++)
    {
      cod next;
      next.first = curr.first + dir[ddx].first;
      next.second = curr.second + dir[ddx].second;

      if(next.first < 0 || next.second < 0 || next.first >= n || next.second >= n)
        continue;

      if(table[next.first][next.second] < min || table[next.first][next.second] > max)
        continue;

      if(visit[next.first][next.second])
        continue;

      visit[next.first][next.second] = true;
      search.push(next);
    }
  }
  return visit[n-1][n-1];
}

/* binary version of bfs searches, to find the minimum gap between max and min */
int binsearch(int start, int end)
{
  if(start == end)
    return start;

  int mid = (start + end) / 2;
  bool flag = false;

  /* iterate through all possible pairs of max, min of the condition, 'gap = mid' */
  for(int idx = 0; idx + mid <= 200; idx++)
  {
    if(bfsearch(idx, idx + mid))
    {
      flag = true;
      break;
    }
  }

  if(flag)
    return binsearch(start, mid);

  else
    return binsearch(mid+1, end);
}


int main()
{
  cin >> n;

  for(int idx = 0; idx < n; idx++)
  {
    for(int jdx = 0; jdx < n; jdx++)
      cin >> table[idx][jdx];
  }

  cout << binsearch(0, 200);

}
