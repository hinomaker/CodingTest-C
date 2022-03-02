#include <iostream>
#include <queue>

using namespace std;

int n; int m;
int r; int c; int d;

int mp[51][51];
int check[51][51];
int ans;

int move_i[4] = { -1,0,1,0 };	// �� �� �� ��
int move_j[4] = { 0,1,0,-1};

void sol() {
	queue<pair<int, int>> q;
	q.push({ r,c });
	int current_d = d;
	while (!q.empty()) {
		int current_i = q.front().first;
		int current_j = q.front().second;
		if (!check[current_i][current_j]) {
			// ������ġ û�� �ȵǾ� ������ û��
			check[current_i][current_j] = 1;
			ans++;
		}
		q.pop();
		int cnt = 0;
		while (cnt < 4) {
			int next_d = (current_d + 3) % 4;
			int next_i = current_i + move_i[next_d];
			int next_j = current_j + move_j[next_d];
			if (next_i >= 0 && next_j >= 0 && next_i < n && next_j < m) {
				if (!mp[next_i][next_j]) {
					// ���� �ƴϰ�
					if (!check[next_i][next_j]) {
						//û�� �ȵǾ� ������ û���Ϸ� ��
						q.push({ next_i,next_j });
						current_d = next_d;
						break;
					}
					else {
						//û�� �Ǿ� ������
						cnt++;
						current_d = next_d;
					}
				}
				else {
					//���̶��
					cnt++;
					current_d = next_d;
				}
			}
		}
		if (cnt == 4) {	// �� ���� ���ƺ���
			int next_i = current_i - move_i[current_d];
			int next_j = current_j - move_j[current_d];
			if (next_i >= 0 && next_j >= 0 && next_i < n && next_j < m) {
				if (!mp[next_i][next_j]) {	//���ƴ϶��
					q.push({ next_i,next_j });
				}
				else {
					break;
				}
			}
			else {
				return;
			}
		}

	}
}

int main() {
	cin >> n >> m;
	cin >> r >> c >> d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mp[i][j];
		}
	}
	sol();
	cout << ans << endl;

}