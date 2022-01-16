#include <iostream>
#include <queue>

using namespace std;

/*
수빈이가 동생을 찾아야함(수빈이가 움직임)
걸을 경우 1초 후 -1 or +1
순간이동할 경우 0초 후 x2
가장 빨리 찾는 시간
*/

// 100001 개의 배열 -> 0으로 초기화.
const int INF = 100001;
int visited[INF];

int solve(int a, int b) {
	// 우선순위 -> 1. *2 순간 이동 -> 0초이므로 우선순위가 제일 높으므로 push front, 나머지 +1과 -1은 나머지 우선순위로 push back
	deque<int> q;
	q.push_back(a);
	visited[a] = 1; // 방문 했으므로
	while (!q.empty()) {
		int x_pos = q.front();
		q.pop_front();	

		if (x_pos == b) return visited[b]-1;

		// 순간이동은 덱의 front
		if (x_pos * 2 < INF && !visited[x_pos *2]) {
			q.push_front(x_pos * 2);
			visited[x_pos * 2] = visited[x_pos];
		}

		if (x_pos + 1 < INF && !visited[x_pos + 1]) {
			visited[x_pos + 1] = visited[x_pos] + 1;
			q.push_back(x_pos + 1);
		}

		if (x_pos - 1 >= 0 && !visited[x_pos - 1]) {
			visited[x_pos - 1] = visited[x_pos] + 1;
			q.push_back(x_pos - 1);
		}
	}
}

int main(void) {
	int a = 0, b = 0;
	cin >> a >> b;
	cout << solve(a, b) << endl;
	return 0;
}
