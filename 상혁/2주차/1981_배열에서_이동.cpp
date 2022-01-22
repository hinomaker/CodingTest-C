#include <iostream>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

#define endl '\n'

const int INF = 247483647;
int N, maxNum, minNum, answer;
int arr[101][101];
bool visited[201][201];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

bool bfs(int target) 
{
	queue<pair<int, int>> q;
	
	for (int i = minNum; i <= maxNum; i++)
	{
		memset(visited, true, sizeof(visited));

		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < N; k++)
			{
				if (arr[j][k] >= i && arr[j][k] <= i + target) visited[j][k] = false;
			}
		}
		
		if (visited[0][0]) continue;
		q.push({ 0,0 });
		visited[0][0] = true;

		while (!q.empty())
		{
			auto item = q.front();
			q.pop();
			int y = item.first;
			int x = item.second;

			if (y == N - 1 && x == N - 1) return true;

			for (int i = 0; i < 4; i++)
			{
				int ny = y + dy[i];
				int nx = x + dx[i];

				if (nx >= 0 && ny >= 0 && nx < N && ny < N && !visited[ny][nx])
				{
					visited[ny][nx] = true;
					q.push({ ny, nx });
				}
			}
		}

	}
	
	return false;
}

void solution()
{
	int left = 0;
	int right = maxNum;
	int mid;

	// bfs(mid)가 true면 최대-최소 값이 mid 값이내에서 1,1부터 N,N까지 탐색이 가능한 상황
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (bfs(mid)) 
		{
			answer = mid;
			right = mid - 1;
		}
		else left = mid + 1;
	}
	cout << answer << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);
	cin >> N;
	minNum = 300;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] > maxNum) maxNum = arr[i][j];
			if (arr[i][j] < minNum) minNum = arr[i][j];
		}
	}

	solution();
}
