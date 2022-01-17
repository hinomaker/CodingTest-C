// 코드 보는 순서 main -> solution
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

#define endl '\n'

int N, K;
bool visited[100001];

void solution() { // bfs
	queue<pair<int, int>> q; // position, time 정보를 담은 pair queue

	q.push({ N, 0 }); // 초기 위치 push

	while (!q.empty())
	{
		auto item = q.front(); // 큐의 첫번째 아이템
    
		q.pop();

		if (item.first == K) // 아이템의 position이 K와 같다면
		{
			cout << item.second << endl; // 아이템의 time을 출력하고 return
			return;
		}

		if (item.first * 2 <= 100000 && !visited[item.first*2]) // overflow 방지를 위해 item의 범위 설정, item.first의 *2 를 방문하지 않았다면
		{
			q.push({ item.first * 2, item.second }); // q에 푸시
			visited[item.first * 2] = true; // 방문 체크
		}

		if (item.first - 1 >= 0 && !visited[item.first-1]) // 위 조건문과 동일한 로직
		{
			q.push({ item.first - 1, item.second + 1 });
			visited[item.first-1] = true;
		}

		if (item.first + 1 <= 100000 && !visited[item.first+1])
		{
			q.push({ item.first + 1, item.second + 1 });
			visited[item.first + 1] = true;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);


	cin >> N >> K;

	solution();
}
