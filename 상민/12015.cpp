#include <iostream>
#include <algorithm>
using namespace std;

/* find lower bound for comp value from [start, end] range */
/* seq[0, 10, 20, 30, 40]->down_lim(seq, start, end, 5) returns 1 */
/* seq[0, 5, 10, 30, 40]->down_lim(seq, start, end, 10) returns 2 */
int down_lim(int *seq, int start, int end, int comp)
{
  int mid = (start + end) / 2;
  while(end - start > 1)
  {
    mid = (start + end) / 2;
    if(seq[mid] < comp)
      start = mid + 1;
    else
      end = mid;
  }
  return start;
}



int main()
{
  /* dynamic programming -> time out */
  /* lowerbound binary search */

  /* intializiation */
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  int input;

  /* array for maintaining longest increasing sequence */
  int seq[N];
  seq[0] = 1000000;

  /* ptr for tracing sequence length */
  int ptr = 0;

  for(int cnt = 0; cnt < N; cnt++)
  {
    cin >> input;
    /* add current input to the sequence */
    if(input > seq[ptr])
      seq[++ptr] = input;
    /* add current input to lowerbound in the sequence */
    else
      seq[down_lim(seq, 0, ptr, input)] = input;
  }

  /* print result */
  cout << ptr + 1;
}
