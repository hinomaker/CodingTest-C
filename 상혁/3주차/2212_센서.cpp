#include <iostream>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define endl '\n'

int N, K, answer;
int arr[10001];

void solution()
{

	vector<int> vec;

	for (int i = 0; i < N-1; i++)
	{
		vec.push_back(arr[i + 1] - arr[i]);
	}

	sort(vec.begin(), vec.end());

	if (K >= N) answer = 0;
	else
	{
		for (int i = 0; i < N - K; i++) answer += vec[i];
	}

	cout << answer << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr + N);

	solution();
}
