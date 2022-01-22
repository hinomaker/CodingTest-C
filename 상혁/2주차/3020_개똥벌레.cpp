#include <iostream>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

#define endl '\n'

const int INF = 2147483647;

int N, H;
int answer = INF;
vector<int> btm;
vector<int> t;
int arr[500001];

void solution()
{

	for (int i = 0; i < H; i++)
	{
		int btm_cnt = btm.size() - (upper_bound(btm.begin(), btm.end(), i) - btm.begin());
		int t_cnt = (upper_bound(t.begin(), t.end(), i) - t.begin());
		arr[btm_cnt + t_cnt]++;
		if (answer > btm_cnt + t_cnt)
		{
			answer = btm_cnt + t_cnt;
		}
	}

	cout << answer << ' ' << arr[answer] << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> N >> H;

	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;

		if (i % 2 == 0)
			btm.push_back(num);
		else
			t.push_back(H-num);
	}

	sort(btm.begin(), btm.end());
	sort(t.begin(), t.end());

	solution();
}
