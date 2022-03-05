#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main(){
  string curr = "first:second third fourth";
  vector<string> lst;

  int start = 0;
  int delim = 0;

  for(; delim <= curr.size(); delim++)
  {
    /*
    delim == curr.size()인 경우,
    curr[delim] 접근 시 에러가 나기 때문에
    이 조건을 가장 앞에 놓아 체크해야 합니다!
    */
    /*
    char[]과 달리 string은 끝에 널문자가 없어서 오늘 얘기한 조건으로는 해결되지 않네요 ㅠㅠ
    */
    if(delim == curr.size() || curr[delim] == ':' || curr[delim] == ' ')
    {
      lst.push_back(curr.substr(start, delim - start));
      start = delim + 1;
    }
  }

  for(int idx = 0; idx < lst.size(); idx++){
    cout << lst[idx] << endl;
  }
}
