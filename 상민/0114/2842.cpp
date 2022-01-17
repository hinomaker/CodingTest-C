#include <iostream>
#include <algorithm>
#include <memory.h>
#include <queue>
#include <cmath>
#include <string.h>
#include <set>

using namespace std;
typedef pair<int, int> cod;

/* map size */
int N;
/* # of delivery destinations = Ks */
int k_cnt;
/* map info constructed with {. , P, K} */
char map[51][51];
/* map info constructed with altitudes */
int alt[50][50];
/* map info constructed with {0, 1} according to its visit-ness */
bool visit[50][50];
/* 8-way direction array */
cod dir[8] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {-1, 1}, {1, -1}, {-1, -1}};
/* start {x,y} coordinate  = post office */
cod post;
/* bfs search queue */
queue<cod> bfsearch;


bool lowhigh(int low, int high)
{
  /* if post office altitude not in range, return false */
  if(alt[post.first][post.second] < low || alt[post.first][post.second] > high)
    return false;

  /* keep track of visited destinations */
  int b_cnt = 0;
  memset(visit, 0, sizeof(visit));
  visit[post.first][post.second] = 1;
  bfsearch.push(post);

  /* bfs search, until every destinations are visited */
  while(!bfsearch.empty())
  {
    cod curr = bfsearch.front();
    bfsearch.pop();

    if(map[curr.first][curr.second] == 'K')
      b_cnt++;

    /* if all destinations are visited */
    if(b_cnt == k_cnt)
      break;

    for(int ddx = 0; ddx < 8; ddx++)
    {
      cod next = {curr.first + dir[ddx].first, curr.second + dir[ddx].second};

      if(next.first < 0 || next.second < 0 || next.first >= N || next.second >= N)
        continue;

      if(alt[next.first][next.second] > high || alt[next.first][next.second] < low)
        continue;

      if(visit[next.first][next.second])
        continue;

      visit[next.first][next.second] = 1;
      bfsearch.push(next);
    }
  }
  /* If all destinations visited */
  if(b_cnt == k_cnt)
  {
    while(!bfsearch.empty())
      bfsearch.pop();
    return true;
  }

  return false;
}


int main()
{
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  /* keep track of all altitudes without duplication */
  vector<int> altlist;
  set<int> dupcheck;

  cin >> N;

  /* input of map char info */
  k_cnt = 0;
  for(int rdx = 0; rdx < N; rdx++)
  {
    cin >> map[rdx];
    for(int cdx = 0; cdx < N; cdx++)
    {
      if(map[rdx][cdx] == 'P')
        post = {rdx, cdx};
      if(map[rdx][cdx] == 'K')
        k_cnt++;
    }
  }

  /* input of alt int info */
  for(int rdx = 0; rdx < N; rdx++)
  {
    for(int cdx = 0; cdx < N; cdx++)
    {
      cin >> alt[rdx][cdx];
      /* if input found in the set, do not add to vector
         in order to prevent duplication */
      if(dupcheck.find(alt[rdx][cdx]) == dupcheck.end())
      {
        dupcheck.insert(alt[rdx][cdx]);
        altlist.push_back(alt[rdx][cdx]);
      }
    }
  }

  /* sort unique altitude list */
  sort(altlist.begin(), altlist.end());

  /* two pointer search */
  int start = 0;
  int end = 0;
  int size = altlist.size();
  int result = 1000000;

  while(start <= end && end < size && start < size)
  {
    /* flag = true, if post officer visit in range of [altlist[start], altlist[end]] possible */
    bool flag = lowhigh(altlist[start], altlist[end]);
    if(flag)
    {
      result = min(result, altlist[end] - altlist[start]);
      start++;
    }
    else
      end++;
  }

  cout << result;
}
