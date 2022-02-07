#include <iostream>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define endl '\n'

int answer = 0;
char arr[12][6];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void down() 
{
	for (int j = 0; j < 6; j++)
	{
		for (int i = 11; i >= 0; i--)
		{
			if (i > 0 && arr[i][j] == '.' && arr[i - 1][j] != '.')
			{
				int pos = i;
				char tmp = arr[i - 1][j];
				arr[i - 1][j] = '.';
				while (pos < 12 && arr[pos][j] == '.')
				{
					pos++;
				}
				arr[pos - 1][j] = tmp;
			}
		}
	}
}

bool solution(int y, int x)
{
	queue<pair<int, int>> q;
	q.push({ y, x });
	bool visited[12][6] = { false, };
	visited[y][x] = true;
	char letter = arr[y][x];

	
	int cnt = 0;
	bool flag = false;
	char tmp[12][6];

	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 6; j++) tmp[i][j] = arr[i][j];
	tmp[y][x] = '.';
	while (!q.empty())
	{
		int yy = q.front().first;
		int xx = q.front().second;
		cnt++;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = yy + dy[i];
			int nx = xx + dx[i];

			if (ny >= 0 && nx >= 0 && ny < 12 && nx < 6 && !visited[ny][nx] && arr[ny][nx] == letter)
			{
				visited[ny][nx] = true;
				tmp[ny][nx] = '.';
				q.push({ ny, nx });
			}
		}
	}

	if (cnt >= 4) flag = true;

	if (flag)
	{
		for (int i = 0; i < 12; i++)
			for (int j = 0; j < 6; j++) arr[i][j] = tmp[i][j];
		return true;
	}

	return false;;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 12; i++)
	{
		string str = "";
		cin >> str;
		for (int j = 0; j < str.length(); j++) arr[i][j] = str[j];
	}

	while (true)
	{
		int tmp = answer;
		bool flag = false;
		for (int i = 11; i >= 0; i--)
		{
			for (int j = 0; j <6; j++)
			{
				if (arr[i][j] != '.')
				{
					if (solution(i, j))
					{
						flag = true;
					}
				}
			}
		}

		
		if (flag)
		{
			answer++;
			down();
		}
		if (tmp == answer) break;
	}

	cout << answer << endl;
}
