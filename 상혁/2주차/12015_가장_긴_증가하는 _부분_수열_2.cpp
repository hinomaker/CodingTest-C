// 이 문제는 주석을 달아놓기 애매한 문제라서
// 혹시 보시고 궁금한 점이 있으시면 카톡으로 답변드리겠습니다

#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

#define endl '\n'

int N;
vector<int> vec;
vector<int> lis;

void solution()
{
	lis.push_back(vec[0]);

	for (int i = 1; i < vec.size(); i++)
	{
		auto lb = lower_bound(lis.begin(), lis.end(), vec[i]); 
		if (lb == lis.end())
		{
			lis.push_back(vec[i]);
		}
		else
		{
			int idx = lb - lis.begin();
			lis[idx] = vec[i];
		}
	}

	cout << lis.size() << endl;
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

	solution();
}
