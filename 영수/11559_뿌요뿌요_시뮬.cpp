#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
using namespace std;


char mp[12][6];
int move_i[4] = { 0,0,1,-1 };
int move_j[4] = { 1,-1,0,0 };
int check[12][6];
int cnt;

vector<pair<int, int>> v;	// puyo 좌표값 저장




void puyo() {
	for (int i = 0; i < v.size(); i++) {
		int current_i = v[i].first;
		int current_j = v[i].second;
		mp[current_i][current_j] = '.';
	}
	while (!v.empty()) {
		v.pop_back();
	}
}

bool bfs(int a, int b) {
	memset(check, 0, sizeof(check));	// check 배열 초기화
	queue<pair<int, int>> q;
	if (mp[a][b] == '.') return false;
	q.push({ a,b });
	check[a][b] = 1;
	v.push_back({ a,b });	// 첫 시작점도 벡터에 추가 (나중에 문자처리용)
	int yes_puyo = 1;	// 뿌요 가능한가? (여기까지 넘어오면 문자 하나있는거)
	while (!q.empty()) {
		int current_i = q.front().first;
		int current_j = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int next_i = current_i + move_i[k];
			int next_j = current_j + move_j[k];
			if (next_i>=0 && next_j>=0 && next_i<12 && next_j<6 && !check[next_i][next_j]) {
				if (mp[next_i][next_j] == mp[a][b]) {
					q.push({ next_i,next_j });
					v.push_back({ next_i, next_j });
					check[next_i][next_j] = 1;
					yes_puyo++;
				}
			}
		}
	}
	if (yes_puyo >= 4) {
		puyo();
		return true;
	}
	else {
		while (yes_puyo--) {	// 4개 안만들어지면 벡터 비우기 (yes_puyo 만큼)
			v.pop_back();
		}
		return false;
	}
}

void refill() {
	for (int j = 0; j < 6; j++) {
		for (int i = 10; i >= 0; i--) {
			for (int k = 11; k > i; k--) {
				if (mp[i][j] != '.' && mp[k][j] == '.') {
					mp[k][j] = mp[i][j];
					mp[i][j] = '.';
					break;
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string tmp;
	for (int i = 0; i < 12; i++) {
		cin >> tmp;
		for (int j = 0; j < tmp.size(); j++) {
			mp[i][j] = tmp[j];
		}
	}
	
	while (1) {
		bool puyo_check = false;
		//memset(check, 0, sizeof(check));
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (bfs(i, j)) { // 한점 기준으로 주변에 같은 문자 4개이상 채워지면 true; 그 외 false;
					puyo_check = true;
				}
			}
		}

		if (puyo_check) {
			/*
			cout << "start" << endl;
			for (int i = 0; i < 12; i++) {
				for (int j = 0; j < 6; j++) {
					cout << mp[i][j] << " ";
				}
				cout << endl;
			}
			*/
			refill();
			/*
			cout << "refill" << endl;
			for (int i = 0; i < 12; i++) {
				for (int j = 0; j < 6; j++) {
					cout << mp[i][j] << " ";
				}
				cout << endl;
			}
			*/
			cnt++;
//			cout << "답 "<<cnt << endl;
		}
		else {
			break;
		}
	}
	cout << cnt << '\n';

}