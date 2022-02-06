#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
  int N1, N2, T;
  string left, right;

  cin >> N1 >> N2;
  cin >> left >> right >> T;
  reverse(left.begin(), left.end());

  int l_ptr = 0;
  int r_ptr = 0;

  for(;l_ptr < N1 - T; l_ptr++)
    cout << left[l_ptr];

  for(;r_ptr < T - N1 && r_ptr < N2; r_ptr++)
    cout << right[r_ptr];

  while(!(l_ptr == N1 && r_ptr == N2))
  {
    if(r_ptr < N2)
      cout << right[r_ptr++];
    if(l_ptr < N1)
      cout << left[l_ptr++];
  }
}
