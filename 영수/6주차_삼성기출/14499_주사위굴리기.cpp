#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int n;
int m;
int mp[21][21];	// �ٴڸ� ����
int k;
int x; int y;	// ������
vector<int> order;
int dice[6];	// �ֻ��� �� �� ����	
int tmp_dice[6];	// ������ �� ����

/* �ֻ��� ����Ʈ
   [0]
[5][1][4]
   [2]
   [3] (�ٴ�)
*/

void dice_roll(int type) {
	for (int i = 0; i < 6; i++) {
		tmp_dice[i] = dice[i];
	}
	if (type == 1) {	//��
		dice[1] = tmp_dice[5];
		dice[3] = tmp_dice[4];
		dice[5] = tmp_dice[3];
		dice[4] = tmp_dice[1];
	}
	if (type == 2) {	// ��
		dice[5] = tmp_dice[1];
		dice[1] = tmp_dice[4];
		dice[4] = tmp_dice[3];
		dice[3] = tmp_dice[5];
	}
	if (type == 3) {	//��
		dice[0] = tmp_dice[3];
		dice[1] = tmp_dice[0];
		dice[2] = tmp_dice[1];
		dice[3] = tmp_dice[2];
	}
	if (type == 4) {	//��
		dice[0] = tmp_dice[1];
		dice[1] = tmp_dice[2];
		dice[2] = tmp_dice[3];
		dice[3] = tmp_dice[0];
	}
}

bool move_mp(int type) {
	if (type == 1) {	//��
		int next_x = x;
		int next_y = y+1;
		if (next_x < n && next_y < m && next_x >= 0 && next_y >= 0) {
			x = next_x;
			y = next_y;
			return true;
		}
		else {
			return false;
		}
	}
	if (type == 2) {	// ��
		int next_x = x;
		int next_y = y-1;
		if (next_x < n && next_y < m && next_x >= 0 && next_y >= 0) {
			x = next_x;
			y = next_y;
			return true;
		}
		else {
			return false;
		}
	}
	if (type == 3) {	//��
		int next_x = x-1;
		int next_y = y;
		if (next_x < n && next_y < m && next_x >= 0 && next_y >= 0) {
			x = next_x;
			y = next_y;
			return true;
		}
		else {
			return false;
		}
	}
	if (type == 4) {	//��
		int next_x = x+1;
		int next_y = y;
		if (next_x < n && next_y < m && next_x >= 0 && next_y >= 0) {
			x = next_x;
			y = next_y;
			return true;
		}
		else {
			return false;
		}
	}
}


void sol() {
	for (int i = 0; i < order.size(); i++) {
		if (move_mp(order[i])) {	// �ֻ��� �̵� ����
			dice_roll(order[i]);	// �ֻ��� ������
			if (mp[x][y] == 0) {	// �̵���ĭ�� 0�̶��
				mp[x][y] = dice[3];	// �ٴڸ鿡 dice �ٴڸ� ����
			}
			else {	// �ٴڸ� 0 �ƴϸ�
				dice[3] = mp[x][y];
				mp[x][y] = 0;
			}
			cout << dice[1] << endl;
		}
	}
}



int main() {
	cin >> n >> m;	// ��n, �� m
	cin >> x >> y;
	cin >> k;
	for (int i = 0; i <n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mp[i][j];
		}
	}
	for (int i = 0; i < k; i++) {
		int tmp;
		cin >> tmp;
		order.push_back(tmp);
	}
	sol();
}