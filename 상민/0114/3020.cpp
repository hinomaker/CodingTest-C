#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;


/* how to replace user-defined function with stl built-in function?
 * given <algorithm> header,

 * "upper_bound(arr.begin(), arr.end(), value) - arr.begin()" : # first idx of arr[idx] > value
 * ex> for array {0, 1, 2, 3} / value = 3 -> returns 4, value = 2 -> returns 3

 * "lower_bound(arr.begin(), arr.end(), value) - arr.begin()" : # first idx of arr[idx] >= value
 * ex> for array {0, 1, 2, 3} / value = 4 -> returns 4, value = 3 -> returns 3
*/


int N, H;

/* find # of stalagmite with height >= comp */
/* lower bound */
int mite_count(int *arr, int start, int end, int comp)
{
  int init_end = end;
  while(start != end)
  {
    int mid = (start + end) / 2;

    if(arr[mid] >= comp)
      end = mid;
    else
      start = mid+1;
  }

  return (start == init_end && arr[init_end] < comp)? start + 1 : start;
}


/* find # of stalactite with height > H-comp */
/* upper bound */
int tite_count(int *arr, int start, int end, int comp)
{
  comp = H - comp;
  int init_end = end;

  while(start != end)
  {
    int mid = (start + end) / 2;
    if(arr[mid] <= comp)
      start = mid + 1;
    else
      end = mid;
  }

  return (start == init_end && arr[init_end] <= comp)? start + 1 : start;
}


int main()
{
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  cin >> N >> H;

  /* stalactite */
  int *dnward = (int*)malloc(sizeof(int) * (N/2));
  /* stalagmite */
  int *upward = (int*)malloc(sizeof(int) * (N/2));
  /* obstacle count at each height*/
  int *cnt = (int*)malloc(sizeof(int) * (H+1));
  memset(cnt, 0, sizeof(cnt));

  /* condition given : N is always even! */
  for(int ndx = 0; ndx < (N/2); ndx++)
    cin >> upward[ndx] >> dnward[ndx];

  sort(upward, upward + (N/2));
  sort(dnward, dnward + (N/2));

  /* iterate through all possible height values */
  for(int hdx = 1; hdx <= H; hdx++)
  {
    int a = mite_count(upward, 0, N/2 - 1, hdx);
    int b = tite_count(dnward, 0, N/2 - 1, hdx);

    a = N/2 - a;
    b = N/2 - b;
    /* calculate obstacle count for each height */
    cnt[hdx] = a + b;
  }

  sort(cnt, cnt + H + 1);

  cout << cnt[1] << " " << tite_count(cnt, 1, H, H-cnt[1]) - mite_count(cnt, 1, H, cnt[1]);
}
