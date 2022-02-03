#include <iostream>
#include <string>
using namespace std;

/* check through divide & conquer */
bool dongho(string input)
{
  int len = input.length();
  if(len == 1)
    return true;

  if(len % 2 == 0)
    return false;

  int mid = (len-1) / 2;

  for(int idx = 0; idx < (len - 1)/ 2; idx++)
  {
    if(input[idx] == input[len-1-idx])
      return false;
  }

  return dongho(input.substr(0, mid)) && dongho(input.substr(mid+1, len));
}

int main()
{
  int T;
  cin >> T;

  string input;
  for(int tdx = 0; tdx < T; tdx++)
  {
    cin >> input;
    string result = dongho(input)? "YES" : "NO";
    cout << result << '\n';
  }
}
