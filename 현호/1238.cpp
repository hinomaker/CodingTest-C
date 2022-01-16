#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;
#define INF 987654321
typedef pair<int, int> queue_type;

int villiage[1001][1001];
int dist[1001][1001];
int birthday = 0;
int whole_person = 0;

map<int, vector<pair<int, int>>> edge_info;
// key는 시작 정점 -> value는 도착 정점 및 weight

void input() {
	int n, m, x = 0;
	cin >> n >> m >> x;
	birthday = x;
	whole_person = n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dist[i][j] = INF;
		}
	} // 거리 정보 설정

	for (int i = 1; i <= m; i++) {
		int s = 0, d = 0, w = 0;
		cin >> s >> d >> w;
		villiage[s][d] = w;

		auto item = edge_info.find(s);
		if (item != edge_info.end())
			// find case
			item->second.push_back(make_pair(d, w));
		else // not find case
		{
			vector<pair<int, int>> elem_vector;
			elem_vector.push_back(make_pair(d, w));
			edge_info.insert(make_pair(s, elem_vector));
		}
	} // 마을 도로 정보 설정.
}

void solution(int start) {
	// 목표 : dist matrix 설정
	priority_queue<queue_type> pq;
	dist[start][start] = 0;
	pq.push(make_pair (start, dist[start][start]));

	while (!pq.empty()) {
		// 사분 방향으로 가는게 아닌 vertex에 인접한 것들로만 이동함.
		int target = pq.top().first;
		int weight = -pq.top().second;

		pq.pop();

		if (dist[start][target] < weight) continue; // 최소 경로를 발견하지 못했으니 패스
		
		// 현재 target에 인접한 정점 vector 찾기.
		auto adj_list = edge_info.find(target)->second;

		for (int i = 0; i < adj_list.size(); i++) {
			int adj_vertex = adj_list[i].first;
			int adj_vertex_new_weight = weight + adj_list[i].second;

			if (adj_vertex_new_weight < dist[start][adj_vertex]) {
				dist[start][adj_vertex] = adj_vertex_new_weight;
				pq.push(make_pair(adj_vertex, -adj_vertex_new_weight));
			}
		}
	}
}

void solve() {
	input();
	/*
	1~4번 사람이 있고 주인공이 3번이면 3번을 제외한 상태에서 구해야 할 것이
	1->3
	2->3
	4->3

	3->1
	3->2
	3->4 를 구해야함.
	*/
	for (int i = 1; i <= whole_person; i++) {
		solution(i);
	}

	int answer = -1;
	for (int i = 1; i <= whole_person; i++) {
		if (i == birthday) continue;
		if (answer < dist[i][birthday] + dist[birthday][i]) answer = dist[i][birthday] + dist[birthday][i];
	}
	cout << answer << endl;
}

int main(void) {
	solve();
	return 0;
}
