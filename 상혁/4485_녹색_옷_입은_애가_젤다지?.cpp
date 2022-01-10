// 코드 보는 순서 main -> solution
// bfs로 풀었는데 알고리즘 분류는 다익스트라로 나와있었습니다
// queue를 pq로 풀면 시간복잡도 측면에서 조금 더 이득을 볼 것 같습니다
// bfs 문제 풀이를 위한 dx, dy 배열은 꼭 외워두시는 게 좋은 것 같습니다
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

#define endl '\n'

int T, N, K, answer, idx;
int dx[4] = { -1, 1, 0, 0 }; // x축 이동을 위한 배열 
int dy[4] = { 0, 0, -1, 1 }; // y축 이동을 위한 배열

void solution(int size) {
  // 원래 전역변수에 선언, 초기화를 하는 것을 선호하는데
  // 각 테스트케이스마다 답을 출력해줘야해서 지역적으로 선언 및 초기화를 해줬습니다
	int arr[126][126] = { 0, };  // 지도 정보를 담고 있는 배열
	int visited[126][126] = { 0, }; // 방문 정보를 담고 있고 int형으로 선언한 이유는 [n, m]에 도착했을 때 드는 비용을 확인하기 위해서입니다.
  // [n, m]에 도착했을 때 드는 비용이 더 크다면 굳이 큐에 푸시할 필요가 없고
  // 낮은 경우에만 큐에 푸시를 해줘서 bfs를 구현하면 됐습니다.
	vector<int> ans;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cin >> arr[i][j];
			visited[i][j] = 2147483647; // MAX_INT
		}
	}

	queue<pair<pair<int, int>, int>> q; // [[X 위치,Y위치], 도달하는 데 소요된 비용] 
	q.push({{ 0, 0 }, arr[0][0]});
	visited[0][0] = arr[0][0]; // 초기 값 설정
	
	while (!q.empty())
	{
		auto item = q.front();
	
		if (item.first.first == size - 1 && item.first.second == size - 1) // item의 x, y가 N, M과 같다면 ans 배열에 push합니다
		{
			ans.push_back(item.second);
		}

		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = item.first.first + dx[i];
			int ny = item.first.second + dy[i];
			if (nx >= 0 && ny >= 0 && nx < size && ny < size)
			{
				int cost = item.second + arr[nx][ny];
				if (visited[nx][ny] > cost) // 방문하는 데 드는 비용이 더 작으면 큐에 푸시를 해줘서 탐색해봅니다
				{
					visited[nx][ny] = cost;
					q.push({ {nx, ny}, cost });
				}
			}
		}
	}

	sort(ans.begin(), ans.end()); // ans 배열을 정렬하고
	answer = ans[0]; // 최소 값을 answer에 초기화해줍니다
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	while (true)
	{
		idx++;
		cin >> T;

		if (T == 0) break;
		
		solution(T);
		cout << "Problem " << idx << ": " << answer << endl;
	}
	
}
