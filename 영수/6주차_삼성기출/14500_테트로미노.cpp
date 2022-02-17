#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int mp[501][501];	// ����ǥ
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
		for (int j = 0; j < m; j++) {	// ��Ž ����
			int tmp_sum = 0;	// max�� ���� ���� ������ i,j���� ��Ž�غ��� max �� ans�� ������ ��
			if (i + 3 < n) {
				tmp_sum = mp[i][j] + mp[i + 1][j] + mp[i + 2][j] + mp[i + 3][j];	// �Ӹ��
				ans = max(ans, tmp_sum);
			}
			if (j + 3 < m) {
				tmp_sum = mp[i][j] + mp[i][j + 1] + mp[i][j + 2] + mp[i][j + 3];	// �� ���
				ans = max(ans, tmp_sum);
			}
			if (i + 1 < n && j + 1 < m) {
				tmp_sum = mp[i][j] + mp[i + 1][j] + mp[i + 1][j + 1] + mp[i][j + 1]; // �� ���
				ans = max(ans, tmp_sum);
			}
			if (i + 2 < n && j + 1 < m) {
				tmp_sum = mp[i][j] + mp[i + 1][j] + mp[i + 2][j] + mp[i][j + 1];	// ����� -1
				ans = max(ans, tmp_sum);
			}
			if (i + 1 < n && j + 2 < m) {
				tmp_sum = mp[i][j] + mp[i + 1][j] + mp[i + 1][j + 1] + mp[i + 1][j + 2]; //��-2
				ans = max(ans, tmp_sum);
			}
			if (i + 2 < n && j - 1 >= 0) {
				tmp_sum = mp[i][j] + mp[i + 1][j] + mp[i + 2][j] + mp[i + 2][j - 1];	// ��-3
				ans = max(ans, tmp_sum);
			}
			if (i + 1 < n && j + 2 < m) {
				tmp_sum = mp[i][j] + mp[i][j + 1] + mp[i][j + 2] + mp[i + 1][j + 2];	// ��-4
				ans = max(ans, tmp_sum);
			}
			if (i + 1 < n && j + 2 < m) {
				tmp_sum = mp[i][j] + mp[i + 1][j] + mp[i][j + 1] + mp[i][j + 2];	// ��-5
				ans = max(ans, tmp_sum);
			}
			if (i + 2 < n && j + 1 < m) {
				tmp_sum = mp[i][j] + mp[i + 1][j] + mp[i + 2][j] + mp[i + 2][j+1];	//��-6
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
			if (i + 2 < n && j + 1 < m) {	//���� ���
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
			if (i + 1 < n && j + 2 < m) { //�Ǹ�� -1
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