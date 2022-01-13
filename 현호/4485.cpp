#include <iostream>
#include<queue>
using namespace std;

#define INF 1000000000

int cave[126][126];
int dist[126][126];
int x[4] = { 0,0,-1,1 };
int y[4] = { -1, 1, 0, 0 };

// 1~125까지 인덱스를 이용하기 위해 전체 126개의 2차원 배열

int main(void) {
	// 동굴의 검은 루비를 -1, 답 matrix를 최대값 INF로 초기화.
	int case_number = 1;
	while (1) {
		int n = 0;
		cin >> n;
		if (n == 0) break;
		else {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					cin >> cave[i][j];
					dist[i][j] = INF;
				}
			}
			priority_queue<pair<int, pair<int, int>>> pq2;
			dist[0][0] = cave[0][0];
			pq2.push(make_pair(-dist[0][0], make_pair(0, 0)));

			while (!pq2.empty()) {
				int cost = -pq2.top().first;
				int cur_x_pos = pq2.top().second.first;
				int cur_y_pos = pq2.top().second.second;
				pq2.pop();

				// 상 하 좌 우 이동.
				for (int i = 0; i < 4; i++) {
					int target_x_move = cur_x_pos + x[i], target_y_move = cur_y_pos + y[i];
					if (target_x_move < 0 || target_x_move >= n || target_y_move < 0 || target_y_move >= n) continue;
					if (dist[target_x_move][target_y_move] > dist[cur_x_pos][cur_y_pos] + cave[target_x_move][target_y_move]) {
						// 최단 경로 발견 
						dist[target_x_move][target_y_move] = dist[cur_x_pos][cur_y_pos] + cave[target_x_move][target_y_move];
						pq2.push(make_pair(-dist[target_x_move][target_y_move], make_pair(target_x_move, target_y_move)));
					}
				}
			}
			cout << "Problem " << case_number << ": " << dist[n-1][n-1] << endl;
			case_number++;
		}
	}
	return 0;
}
