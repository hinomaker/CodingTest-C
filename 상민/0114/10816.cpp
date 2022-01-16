#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> card;

/* find lower bound for comp value from [start, end] range */
/* [0, 10, 10, 10, 20]->down_lim(start, end, 10) returns 1 */
int down_lim(int start, int end, int comp)
{
  int mid;
  while(start != end)
  {
    mid = (start + end) / 2;
    if(card[mid] < comp)
      start = mid + 1;
    else
      end = mid;
  }
  return start;
}

/* find upper bound for comp value from [start, end] range */
/* [0, 10, 10, 10, 20] -> up_lim(start, end, 10) returns 4 */
int up_lim(int start, int end, int comp)
{
  int init_end = end;
  int mid;
  while(start != end)
  {
    mid = (start + end) / 2;
    if(card[mid] <= comp)
      start = mid + 1;
    else
      end = mid;
  }
  /* if upper bound idx points last element, add 1 */
  /* [0, 10, 10, 10, 20] -> up_lim(start, end, 20) returns 5 now */
  return (start == init_end && card[init_end] == comp)? start+1 : start;
}



int main()
{
    /* initialization */
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N, M, comp;

    cin >> N;
    for(int idx = 0; idx < N; idx++)
    {
      int input;
      cin >> input;
      card.push_back(input);
    }
    /* sort list for lowerbound/upperbound binary search */
    sort(card.begin(), card.end());

    cin >> M;
    for(int idx = 0; idx < M; idx++)
    {
      cin >> comp;
      /* print result */
      cout << up_lim(0, N-1, comp) - down_lim(0, N-1, comp) << " ";
    }
}
