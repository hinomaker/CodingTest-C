#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

int main()
{
  int N;  int K;
  cin >> N >> K;

  set<int> sensor;
  int input;
  vector<int> dist;

  for(int idx = 0; idx < N; idx++)
  {
    cin >> input;
    if(sensor.find(input) == sensor.end())
      sensor.insert(input);
  }

  auto prev = sensor.begin();
  auto iter = sensor.begin();
  iter++;

  for(; iter != sensor.end();)
  {
    dist.push_back((*iter) - (*prev));
    iter++;
    prev++;
  }

  sort(dist.begin(), dist.end(), less<int>());

  int result = 0;

 /* greedy: exclude (K-1) longest intervals */
  for(int idx = 0; idx < (int)dist.size()-K+1; idx++)
    result += dist[idx];

  cout << result << '\n';

}
