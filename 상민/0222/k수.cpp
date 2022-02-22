#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;

/* prime number check */
bool isprime(long num)
{
  if(num == 1)
    return 0;

  for(int idx = 2; idx <= sqrt(num); idx++)
  {
    if(num % idx == 0)
      return 0;
  }

  return 1;
}


int solution(int n, int k)
{
    int answer = 0;
    string ntok = "";

    /* convert to k-expression */
    while(n != 0)
    {
      ntok += to_string(n % k);
      n /= k;
    }
    reverse(ntok.begin(), ntok.end());

    /* tokenizer by '0' */
    vector<string> token;
    int iter = 0;
    int jter = 0;

    for(; jter < ntok.length(); jter++)
    {
      if(ntok[jter] == '0' && iter != jter)
      {
        token.push_back(ntok.substr(iter, jter-iter));
        iter = jter + 1;
      }
      else if(ntok[jter] == '0' && iter == jter)
        iter++;
    }

    if(iter != jter)
      token.push_back(ntok.substr(iter, jter-iter));

    /* prime check for tokens */
    for(int tdx = 0; tdx < token.size(); tdx++)
      answer += isprime(stol(token[tdx]));

    return answer;
}
