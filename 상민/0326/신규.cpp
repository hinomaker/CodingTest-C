#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string new_id)
{
  string answer = "";

  for(int idx = 0; idx < new_id.length(); idx++)
  {
    /* phase 1 */
    if(new_id[idx] <= 'Z' && new_id[idx] >= 'A')
      answer += new_id[idx] - 'A' + 'a';
    /* phase 2 */
    else if(
      (new_id[idx] <= '9' && new_id[idx] >= '0') ||
      (new_id[idx] == '_' || new_id[idx] == '-') ||
      (new_id[idx] <= 'z' && new_id[idx] >= 'a') ||
      (new_id[idx] == '.')
    )
      answer += new_id[idx];
  }
  /* phase 3 */
  for(int idx = 1; idx < answer.length();)
  {
    if(answer[idx] == '.' && answer[idx-1] == '.')
      answer = answer.substr(0, idx-1) + answer.substr(idx);
    else
      idx++;
  }
  /* phase 4 */
  if(answer[0] == '.')
    answer = answer.substr(1, answer.length()-1);
  if(answer[answer.length()-1] == '.')
    answer = answer.substr(0, answer.length()-1);
  /* phase 5, 6 */
  if(!answer.length())
    answer += 'a';
  if(answer.length() >= 16)
    answer = answer.substr(0, 15);
  if(answer[answer.length()-1] == '.')
    answer = answer.substr(0, answer.length()-1);
  /* phase 7 */
  if(answer.length() <= 2)
  {
    while(answer.length() != 3)
      answer += answer[answer.length()-1];
  }
  return answer;
}
