#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

#define endl '\n'

int N, M;
vector<int> vec;

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
	cin >> M;

	for (int i = 0; i < M; i++)
	{
		int num;
		cin >> num;
		int lb_idx = lower_bound(vec.begin(), vec.end(), num) - vec.begin();  // vec에서 num '이상'의 수가 등장하는 idx
		int ub_idx = upper_bound(vec.begin(), vec.end(), num) - vec.begin(); // vec에서 num '초과'의 수가 등장하는 idx

		cout << ub_idx - lb_idx << ' ';
	}
  
}
