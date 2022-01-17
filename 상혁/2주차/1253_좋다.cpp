#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

#define endl '\n'

int N, answer;
vector<long long> vec;

void solution()
{

	for (int i = 0; i < vec.size(); i++)
	{
		for (int j = 0; j < vec.size(); j++)
		{
			if (i == j) continue;
			int num = vec[i] - vec[j]; // vec[i]가 '좋은' 수이려면 vec[j] + 어떤 수가 vec[i]가 되어야함
      // vec[i] - vec[j]가 vec에 존재하면 '좋은 수'
			
			int ub_idx = upper_bound(vec.begin(), vec.end(), num) - vec.begin();
			int lb_idx = lower_bound(vec.begin(), vec.end(), num) - vec.begin();
			int cnt = ub_idx - lb_idx; // 동일한 원소의 개수 (1인 경우 유일)
			if (lb_idx < vec.size() && vec[lb_idx] == num) // lb_idx가 유효한 범위 내 && vec[lb_idx]가 num일 때
			{
				if (vec[lb_idx] != vec[i] && vec[lb_idx] != vec[j] || // lb_idx가 i, j랑 겹치면 안된당 (서로 다른 두 수의 합이니까)
					vec[lb_idx] == vec[i] && cnt > 2 || // 만약 i 또는 j랑 동일하다면, 그 중복된 수가 3개 이상일 때만 좋은 수로 취급 가능
					vec[lb_idx] == vec[j] && cnt > 2 ) // 예를 들어서 0 0 0 이렇게 있는 경우 0이 중복된 수가 3개, 각각 그 자신을 제외하고 나머지 두 수록 좋은 수임을 증명할 수 있다
				{
					answer++;
					break;
				}
		
			}
		}
	}

	cout << answer << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		vec.push_back(num);
	}

	sort(vec.begin(), vec.end());

	solution();
}
