#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

int mp[1001][1001];
int check[1001][1001];
int dist[1001][1001];

int move_i[3] = { 1,0,1 };
int move_j[3] = { 0,1,1 };
int n; int m;

void dijkstra() {
	priority_queue<pair<int, pair<int, int>>> pq;	// (ªÁ≈¡,¡¬«•)
	pq.push({ 1,{0,0} });
	//check[0][0] = 1;

	while (!pq.empty()) {
		int current_i = pq.top().second.first;
		int current_j = pq.top().second.second;
		int candy = pq.top().first;
		pq.pop();
		for (int k = 0; k < 3; k++) {
			int next_i = current_i + move_i[k];
			int next_j = current_j + move_j[k];
			if (next_i >= 0 && next_j >= 0 && next_i < n && next_j < m) {
				if (candy + mp[next_i][next_j] > dist[next_i][next_j]) {
					dist[next_i][next_j] = candy + mp[next_i][next_j];
					pq.push({ (candy + mp[next_i][next_j]),{next_i,next_j} });
				}
			}
		}
	}

}

int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int tmp;
			cin >> tmp;
			mp[i][j] = tmp;
		}
	}

	//	dijkstra();
	dist[1][1] = mp[1][1];
	dist[1][2] = dist[1][1] + mp[1][2];
	dist[2][1] = dist[1][1] + mp[2][1];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dist[i][j] = max(dist[i - 1][j] + mp[i][j], dist[i][j - 1] + mp[i][j]);
			dist[i][j] = max(dist[i][j], dist[i - 1][j - 1] + mp[i][j]);
		}
	}
	cout << dist[n][m] << endl;

}