#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <deque>
#include <cmath>
using namespace std;

int n;
int mp[21][21];	// 원본
int cp_mp[21][21];	//복사본
vector<int> dir;
int ans;

void sol() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cp_mp[i][j] = mp[i][j];
		}
	}
	for (int k = 0; k < dir.size(); k++) {
		if (dir[k] == 0) {	//동
			for (int i = 0; i < n; i++) {
				vector<int> tmp_mp;
				for (int j = 0; j < n; j++) {	// 일단 하나의 행 (서-동 방향으로 push)
					if (cp_mp[i][j]) {	// 0 아닌것 push 해서 비교 할 것 
						tmp_mp.push_back(cp_mp[i][j]);
						cp_mp[i][j] = 0;
					}
				}
				if (tmp_mp.size() > 1) {
					for (int j = 0; j < tmp_mp.size() - 1; j++) {	// tmp_mp를 서-동 방향으로 합칠 수 있는지 점검 할 것
						if ((tmp_mp[j] == tmp_mp[j + 1]) && tmp_mp[j] != 0) {
							tmp_mp[j + 1] *= 2;
							tmp_mp[j] = 0;	// 나중에 0 인것들은 push 안할것
							j = j + 1;	// 2개 합쳤으니까 그다음걸로 가야함 (0,1) 합치면, (2,3) 되는지 봐야지
						}
					}
				}
				int idx = n-1;
				for (int j = tmp_mp.size() - 1; j >= 0; j--) {	// 동쪽으로 밀었으니까 mp 가장 우측부터 tmp_mp값 push할 것
					if (tmp_mp[j]) {// tmp_mp 값 있으면
						cp_mp[i][idx] = tmp_mp[j];
						idx--;
					}
				}
			}
		}
		if (dir[k] == 1) {	// 서
			for (int i = 0; i < n; i++) {
				vector<int> tmp_mp;
				for (int j = 0; j < n; j++) {	// 일단 하나의 행 (서-동 방향으로 push)
					if (cp_mp[i][j]) {
						tmp_mp.push_back(cp_mp[i][j]);
						cp_mp[i][j] = 0;
					}
				}
				if (tmp_mp.size() > 1) {
					for (int j = 0; j < tmp_mp.size() - 1; j++) {	// tmp_mp를 서-동 방향으로 합칠 수 있는지 점검 할 것
						if ((tmp_mp[j] == tmp_mp[j + 1]) && tmp_mp[j] != 0) {
							tmp_mp[j + 1] *= 2;
							tmp_mp[j] = 0;	// 나중에 0 인것들은 push 안할것
							j = j + 1;	// 2개 합쳤으니까 그다음걸로 가야함 (0,1) 합치면, (2,3) 되는지 봐야지
						}
					}
				}/*
				if (tmp_mp.size() > 1) {
					for (int j = tmp_mp.size() - 1; j >= 1; j--) {	// tmp_mp를 서-동 방향으로 합칠 수 있는지 점검 할 것
						if ((tmp_mp[j] == tmp_mp[j - 1]) && tmp_mp[j] != 0) {
							tmp_mp[j] *= 2;
							tmp_mp[j - 1] = 0;	// 나중에 0 인것들은 push 안할것
							j = j - 1;	// 2개 합쳤으니까 그다음걸로 가야함 (0,1) 합치면, (2,3) 되는지 봐야지
						}
					}
				}
				*/
				int idx = 0;
				for (int j = 0; j < tmp_mp.size(); j++) {	// 동쪽으로 밀었으니까 mp 가장 우측부터 tmp_mp값 push할 것
					if (tmp_mp[j]) {// tmp_mp 값 있으면
						cp_mp[i][idx] = tmp_mp[j];
						idx++;
					}
				}
			}
		}

		if (dir[k] == 2) {	// 남
			for (int j = 0; j < n; j++) {
				vector<int> tmp_mp;
				for (int i = 0; i < n; i++) {	// 일단 하나의 행 (북-남 방향으로 push)
					if (cp_mp[i][j]) {
						tmp_mp.push_back(cp_mp[i][j]);
						cp_mp[i][j] = 0;
					}
				}
				if (tmp_mp.size() > 1) {
					for (int i = 0; i < tmp_mp.size() - 1; i++) {	// tmp_mp를 서-동 방향으로 합칠 수 있는지 점검 할 것
						if ((tmp_mp[i] == tmp_mp[i + 1]) && tmp_mp[i] != 0) {
							tmp_mp[i + 1] *= 2;
							tmp_mp[i] = 0;	// 나중에 0 인것들은 push 안할것
							i = i + 1;	// 2개 합쳤으니까 그다음걸로 가야함 (0,1) 합치면, (2,3) 되는지 봐야지
						}
					}
				}
				int idx = n-1; // 남쪽부터 채울것
				for (int i = tmp_mp.size()-1; i >=0; i--) {	// 동쪽으로 밀었으니까 mp 가장 우측부터 tmp_mp값 push할 것
					if (tmp_mp[i]) {// tmp_mp 값 있으면
						cp_mp[idx][j] = tmp_mp[i];
						idx--;
					}
				}
			}
		}

		if (dir[k] == 3) {	//북
			for (int j = 0; j < n; j++) {
				vector<int> tmp_mp;
				for (int i = 0; i < n; i++) {	// 일단 하나의 행 (북-남 방향으로 push)
					if (cp_mp[i][j]) {	
						tmp_mp.push_back(cp_mp[i][j]);
						cp_mp[i][j] = 0;
					}
				}
				if (tmp_mp.size() > 1) {
					for (int i = 0; i < tmp_mp.size() - 1; i++) {	// tmp_mp를 서-동 방향으로 합칠 수 있는지 점검 할 것
						if ((tmp_mp[i] == tmp_mp[i + 1]) && tmp_mp[i] != 0) {
							tmp_mp[i + 1] *= 2;
							tmp_mp[i] = 0;	// 나중에 0 인것들은 push 안할것
							i = i + 1;	// 2개 합쳤으니까 그다음걸로 가야함 (0,1) 합치면, (2,3) 되는지 봐야지
						}
					}
				}
				/*
				if (tmp_mp.size() > 1) {
					for (int i = tmp_mp.size() - 1; i >= 1; i--) {	// tmp_mp를 서-동 방향으로 합칠 수 있는지 점검 할 것
						if ((tmp_mp[i] == tmp_mp[i - 1]) && tmp_mp[i] != 0) {
							tmp_mp[i] *= 2;
							tmp_mp[i - 1] = 0;	// 나중에 0 인것들은 push 안할것
							i = i - 1;	// 2개 합쳤으니까 그다음걸로 가야함 (0,1) 합치면, (2,3) 되는지 봐야지
						}
					}
				}
				*/
				int idx = 0; // 북쪽부터 채울것
				for (int i = 0; i < tmp_mp.size(); i++) {	// 동쪽으로 밀었으니까 mp 가장 우측부터 tmp_mp값 push할 것
					if (tmp_mp[i]) {// tmp_mp 값 있으면
						cp_mp[idx][j] = tmp_mp[i];
						idx++;
					}
				}
			}
		}
	}

}

void back() {
	if (dir.size() == 5) {
		sol();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				ans = max(ans, cp_mp[i][j]);
			}
		}
		return;
	}
	for (int i = 0; i < 4; i++) {
		dir.push_back(i);
		back();
		dir.pop_back();
	}
}


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mp[i][j];
		}
	}
	back();
	cout << ans << endl;
}