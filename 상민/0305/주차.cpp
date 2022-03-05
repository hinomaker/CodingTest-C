#include <map>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records)
{
    vector<int> answer;
    map<string, int> time;

    for(int rdx = 0; rdx < records.size(); rdx++)
    {
      string curr = records[rdx];
      vector<string> lst;

      int start = 0;
      int delim = 0;

      for(; delim < curr.size(); delim++)
      {
        if(curr[delim] == ':' || curr[delim] == ' ')
        {
          lst.push_back(curr.substr(start, delim - start));
          start = delim + 1;
        }
      }

      if(curr[11] == 'I')
        time[lst[2]] += (23 - stoi(lst[0])) * 60 + (59 - stoi(lst[1]));
      else
        time[lst[2]] -= (23 - stoi(lst[0])) * 60 + (59 - stoi(lst[1]));
    }

    for(auto iter = time.begin(); iter != time.end(); iter++)
    {
      int t_park = (*iter).second;
      int price = (t_park <= fees[0])? fees[1] : fees[1] + (t_park - fees[0] + fees[2] - 1) / fees[2] * fees[3];
      answer.push_back(price);
    }

    return answer;
}
