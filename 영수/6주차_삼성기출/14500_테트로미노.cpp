#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int mp[501][501];	// 점수표
int n;
int m;
int ans;

int main() {
	cin >> n;
	cin >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mp[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {	// 완탐 시작
			int tmp_sum = 0;	// max값 지속 갱신 기준점 i,j에서 완탐해보고 max 값 ans에 저장할 것
			if (i + 3 < n) {
				tmp_sum = mp[i][j] + mp[i + 1][j] + mp[i + 2][j] + mp[i + 3][j];	// ㅣ모양
				ans = max(ans, tmp_sum);
			}
			if (j + 3 < m) {
				tmp_sum = mp[i][j] + mp[i][j + 1] + mp[i][j + 2] + mp[i][j + 3];	// ㅡ 모양
				ans = max(ans, tmp_sum);
			}
			if (i + 1 < n && j + 1 < m) {
				tmp_sum = mp[i][j] + mp[i + 1][j] + mp[i + 1][j + 1] + mp[i][j + 1]; // ㅁ 모양
				ans = max(ans, tmp_sum);
			}
			if (i + 2 < n && j + 1 < m) {
				tmp_sum = mp[i][j] + mp[i + 1][j] + mp[i + 2][j] + mp[i][j + 1];	// ㄴ모양 -1
				ans = max(ans, tmp_sum);
			}
			if (i + 1 < n && j + 2 < m) {
				tmp_sum = mp[i][j] + mp[i + 1][j] + mp[i + 1][j + 1] + mp[i + 1][j + 2]; //ㄴ-2
				ans = max(ans, tmp_sum);
			}
			if (i + 2 < n && j - 1 >= 0) {
				tmp_sum = mp[i][j] + mp[i + 1][j] + mp[i + 2][j] + mp[i + 2][j - 1];	// ㄴ-3
				ans = max(ans, tmp_sum);
			}
			if (i + 1 < n && j + 2 < m) {
				tmp_sum = mp[i][j] + mp[i][j + 1] + mp[i][j + 2] + mp[i + 1][j + 2];	// ㄴ-4
				ans = max(ans, tmp_sum);
			}
			if (i + 1 < n && j + 2 < m) {
				tmp_sum = mp[i][j] + mp[i + 1][j] + mp[i][j + 1] + mp[i][j + 2];	// ㄴ-5
				ans = max(ans, tmp_sum);
			}
			if (i + 2 < n && j + 1 < m) {
				tmp_sum = mp[i][j] + mp[i + 1][j] + mp[i + 2][j] + mp[i + 2][j+1];	//ㄴ-6
				ans = max(ans, tmp_sum);
			}
			if (i + 1 < n && j - 2 >= 0) {
				tmp_sum = mp[i + 1][j - 2] + mp[i + 1][j - 1] + mp[i + 1][j] + mp[i][j];
				ans = max(ans, tmp_sum);
			}
			if (i + 2 < n && j + 1 < m) {
				tmp_sum = mp[i][j] + mp[i][j + 1] + mp[i + 1][j + 1] + mp[i + 2][j + 1];
				ans = max(ans, tmp_sum);
			}
			if (i + 2 < n && j + 1 < m) {	//ㄱㄴ 모양
				tmp_sum = mp[i][j + 1] + mp[i + 1][j + 1] + mp[i + 1][j] + mp[i + 2][j];
				ans = max(ans, tmp_sum);
			}
			if (i + 1 < n && j + 2 < m) {
				tmp_sum = mp[i][j] + mp[i][j + 1] + mp[i + 1][j + 1] + mp[i + 1][j + 2];
				ans = max(ans, tmp_sum);
			}
			if (i + 1 < n && j + 2 < m) {
				tmp_sum = mp[i + 1][j] + mp[i + 1][j + 1] + mp[i][j + 1] + mp[i][j + 2];
				ans = max(ans, tmp_sum);
			}
			if (i + 2 < n && j + 1 < m) {
				tmp_sum = mp[i][j] + mp[i + 1][j] + mp[i + 1][j + 1] + mp[i + 2][j + 1];
				ans = max(ans, tmp_sum);
			}
			if (i + 1 < n && j + 2 < m) { //ㅗ모양 -1
				tmp_sum = mp[i][j] + mp[i][j + 1] + mp[i + 1][j + 1] + mp[i][j + 2];
				ans = max(ans, tmp_sum);
			}
			if (i + 2 < n && j + 1 < m) {
				tmp_sum = mp[i][j] + mp[i + 1][j] + mp[i + 2][j] + mp[i + 1][j + 1];
				ans = max(ans, tmp_sum);
			}
			if (i+1 <n && j + 2 < m) {
				tmp_sum = mp[i + 1][j] + mp[i + 1][j + 1] + mp[i][j + 1] + mp[i + 1][j + 2];
				ans = max(ans, tmp_sum);
			}
			if (i + 2 < n && j + 1 < m) {
				tmp_sum = mp[i + 1][j] + mp[i + 1][j + 1] + mp[i][j + 1] + mp[i + 2][j + 1];
				ans = max(ans, tmp_sum);
			}
		}
	}
	cout << ans << endl;
}