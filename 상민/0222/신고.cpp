#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k)
{
  vector<int> answer(id_list.size(), 0);
  vector<int> repcnt(id_list.size(), 0);
  map<int, vector<int>> relation;
  sort(report.begin(), report.end());

  string src = "", dst = "";

  for(int rdx = 0; rdx < report.size(); rdx++)
  {
    int delim = 0;
    for(; delim < report[rdx].length(); delim++)
    {
      if(report[rdx][delim] == ' ')
        break;
    }

    string cur_src = report[rdx].substr(0, delim);
    string cur_dst = report[rdx].substr(delim + 1);

    if(cur_src == src && cur_dst == dst)
      continue;

    int sdx = 0, ddx = 0;

    for(; sdx < id_list.size(); sdx++)
    {
      if(id_list[sdx] == cur_src)
        break;
    }

    for(; ddx < id_list.size(); ddx++)
    {
      if(id_list[ddx] == cur_dst)
        break;
    }

    relation[sdx].push_back(ddx);
    repcnt[ddx]++;
    src = cur_src;
    dst = cur_dst;
  }

  for(int idx = 0; idx < id_list.size(); idx++)
  {
    int result = 0;

    for(int jdx = 0; jdx < relation[idx].size(); jdx++)
    {
      if(repcnt[relation[idx][jdx]] >= k)
        result++;
    }

    answer[idx] = result;
  }
  return answer;
}
