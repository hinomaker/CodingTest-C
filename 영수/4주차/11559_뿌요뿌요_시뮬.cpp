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

vector<pair<int, int>> v;	// puyo ��ǥ�� ����




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
	memset(check, 0, sizeof(check));	// check �迭 �ʱ�ȭ
	queue<pair<int, int>> q;
	if (mp[a][b] == '.') return false;
	q.push({ a,b });
	check[a][b] = 1;
	v.push_back({ a,b });	// ù �������� ���Ϳ� �߰� (���߿� ����ó����)
	int yes_puyo = 1;	// �ѿ� �����Ѱ�? (������� �Ѿ���� ���� �ϳ��ִ°�)
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
		while (yes_puyo--) {	// 4�� �ȸ�������� ���� ���� (yes_puyo ��ŭ)
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
				if (bfs(i, j)) { // ���� �������� �ֺ��� ���� ���� 4���̻� ä������ true; �� �� false;
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
//			cout << "�� "<<cnt << endl;
		}
		else {
			break;
		}
	}
	cout << cnt << '\n';

}