#include <iostream>
#include <algorithm>

using namespace std;

int N;
int numlist[2000];
/* find lower bound for comp value from [start, end] range */
/* [0, 10, 10, 10, 20]->down_lim(start, end, 10) returns 1 */
int down_lim(int start, int end, int comp)
{
  int mid;
  while(start != end)
  {
    mid = (start + end) / 2;
    if(numlist[mid] < comp)
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
  /* save end idx */
  int init_end = end;
  int mid;
  while(start != end)
  {
    mid = (start + end) / 2;
    if(numlist[mid] <= comp)
      start = mid + 1;
    else
      end = mid;
  }
  /* if upper bound idx points last element, add 1 */
  /* [0, 10, 10, 10, 20] -> up_lim(start, end, 20) returns 5 now */
  return (start == init_end && numlist[init_end] == comp)? start+1 : start;
}


int main()
{
  /* initialization */
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  cin >> N;
  for(int idx = 0; idx < N; idx++)
    cin >> numlist[idx];

  /* sort list for lowerbound/upperbound binary search */
  sort(numlist, numlist + N);

  int cnt = 0;

  for(int idx = 0; idx < N; idx++)
  {
    /* pointer 1 */
    int curr = numlist[idx];

    for(int jdx = 0; jdx < N; jdx++)
    {
      /* if two pointers indicate same idx, skip*/
      if(jdx == idx)
        continue;
      /* pointer 2 */
      int next = numlist[jdx];
      /* find upperbound/lowerbound to check for # */
      int a = down_lim(0, N-1, curr-next);
      int b = up_lim(0, N-1, curr-next);
      int check = (int)(int)(a <= idx && idx < b) + (int)(a <= jdx && jdx < b);
      /* validity check -> break */
      if(b-a > check)
      {
        cnt++;
        break;
      }
    }
  }

  /* print result */
  cout << cnt;
}
