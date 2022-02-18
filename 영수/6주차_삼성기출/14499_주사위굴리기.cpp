#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int n;
int m;
int mp[21][21];	// 바닥면 저장
int k;
int x; int y;	// 시작점
vector<int> order;
int dice[6];	// 주사위 면 값 저장	
int tmp_dice[6];	// 뒤집기 전 저장

/* 주사위 디폴트
   [0]
[5][1][4]
   [2]
   [3] (바닥)
*/

void dice_roll(int type) {
	for (int i = 0; i < 6; i++) {
		tmp_dice[i] = dice[i];
	}
	if (type == 1) {	//동
		dice[1] = tmp_dice[5];
		dice[3] = tmp_dice[4];
		dice[5] = tmp_dice[3];
		dice[4] = tmp_dice[1];
	}
	if (type == 2) {	// 서
		dice[5] = tmp_dice[1];
		dice[1] = tmp_dice[4];
		dice[4] = tmp_dice[3];
		dice[3] = tmp_dice[5];
	}
	if (type == 3) {	//남
		dice[0] = tmp_dice[3];
		dice[1] = tmp_dice[0];
		dice[2] = tmp_dice[1];
		dice[3] = tmp_dice[2];
	}
	if (type == 4) {	//북
		dice[0] = tmp_dice[1];
		dice[1] = tmp_dice[2];
		dice[2] = tmp_dice[3];
		dice[3] = tmp_dice[0];
	}
}

bool move_mp(int type) {
	if (type == 1) {	//동
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
	if (type == 2) {	// 서
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
	if (type == 3) {	//북
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
	if (type == 4) {	//남
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
		if (move_mp(order[i])) {	// 주사위 이동 가능
			dice_roll(order[i]);	// 주사위 굴리기
			if (mp[x][y] == 0) {	// 이동한칸이 0이라면
				mp[x][y] = dice[3];	// 바닥면에 dice 바닥면 복사
			}
			else {	// 바닥면 0 아니면
				dice[3] = mp[x][y];
				mp[x][y] = 0;
			}
			cout << dice[1] << endl;
		}
	}
}



int main() {
	cin >> n >> m;	// 행n, 열 m
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