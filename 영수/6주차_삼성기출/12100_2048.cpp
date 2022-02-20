#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <deque>
#include <cmath>
using namespace std;

int n;
int mp[21][21];	// ����
int cp_mp[21][21];	//���纻
vector<int> dir;
int ans;

void sol() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cp_mp[i][j] = mp[i][j];
		}
	}
	for (int k = 0; k < dir.size(); k++) {
		if (dir[k] == 0) {	//��
			for (int i = 0; i < n; i++) {
				vector<int> tmp_mp;
				for (int j = 0; j < n; j++) {	// �ϴ� �ϳ��� �� (��-�� �������� push)
					if (cp_mp[i][j]) {	// 0 �ƴѰ� push �ؼ� �� �� �� 
						tmp_mp.push_back(cp_mp[i][j]);
						cp_mp[i][j] = 0;
					}
				}
				if (tmp_mp.size() > 1) {
					for (int j = 0; j < tmp_mp.size() - 1; j++) {	// tmp_mp�� ��-�� �������� ��ĥ �� �ִ��� ���� �� ��
						if ((tmp_mp[j] == tmp_mp[j + 1]) && tmp_mp[j] != 0) {
							tmp_mp[j + 1] *= 2;
							tmp_mp[j] = 0;	// ���߿� 0 �ΰ͵��� push ���Ұ�
							j = j + 1;	// 2�� �������ϱ� �״����ɷ� ������ (0,1) ��ġ��, (2,3) �Ǵ��� ������
						}
					}
				}
				int idx = n-1;
				for (int j = tmp_mp.size() - 1; j >= 0; j--) {	// �������� �о����ϱ� mp ���� �������� tmp_mp�� push�� ��
					if (tmp_mp[j]) {// tmp_mp �� ������
						cp_mp[i][idx] = tmp_mp[j];
						idx--;
					}
				}
			}
		}
		if (dir[k] == 1) {	// ��
			for (int i = 0; i < n; i++) {
				vector<int> tmp_mp;
				for (int j = 0; j < n; j++) {	// �ϴ� �ϳ��� �� (��-�� �������� push)
					if (cp_mp[i][j]) {
						tmp_mp.push_back(cp_mp[i][j]);
						cp_mp[i][j] = 0;
					}
				}
				if (tmp_mp.size() > 1) {
					for (int j = 0; j < tmp_mp.size() - 1; j++) {	// tmp_mp�� ��-�� �������� ��ĥ �� �ִ��� ���� �� ��
						if ((tmp_mp[j] == tmp_mp[j + 1]) && tmp_mp[j] != 0) {
							tmp_mp[j + 1] *= 2;
							tmp_mp[j] = 0;	// ���߿� 0 �ΰ͵��� push ���Ұ�
							j = j + 1;	// 2�� �������ϱ� �״����ɷ� ������ (0,1) ��ġ��, (2,3) �Ǵ��� ������
						}
					}
				}/*
				if (tmp_mp.size() > 1) {
					for (int j = tmp_mp.size() - 1; j >= 1; j--) {	// tmp_mp�� ��-�� �������� ��ĥ �� �ִ��� ���� �� ��
						if ((tmp_mp[j] == tmp_mp[j - 1]) && tmp_mp[j] != 0) {
							tmp_mp[j] *= 2;
							tmp_mp[j - 1] = 0;	// ���߿� 0 �ΰ͵��� push ���Ұ�
							j = j - 1;	// 2�� �������ϱ� �״����ɷ� ������ (0,1) ��ġ��, (2,3) �Ǵ��� ������
						}
					}
				}
				*/
				int idx = 0;
				for (int j = 0; j < tmp_mp.size(); j++) {	// �������� �о����ϱ� mp ���� �������� tmp_mp�� push�� ��
					if (tmp_mp[j]) {// tmp_mp �� ������
						cp_mp[i][idx] = tmp_mp[j];
						idx++;
					}
				}
			}
		}

		if (dir[k] == 2) {	// ��
			for (int j = 0; j < n; j++) {
				vector<int> tmp_mp;
				for (int i = 0; i < n; i++) {	// �ϴ� �ϳ��� �� (��-�� �������� push)
					if (cp_mp[i][j]) {
						tmp_mp.push_back(cp_mp[i][j]);
						cp_mp[i][j] = 0;
					}
				}
				if (tmp_mp.size() > 1) {
					for (int i = 0; i < tmp_mp.size() - 1; i++) {	// tmp_mp�� ��-�� �������� ��ĥ �� �ִ��� ���� �� ��
						if ((tmp_mp[i] == tmp_mp[i + 1]) && tmp_mp[i] != 0) {
							tmp_mp[i + 1] *= 2;
							tmp_mp[i] = 0;	// ���߿� 0 �ΰ͵��� push ���Ұ�
							i = i + 1;	// 2�� �������ϱ� �״����ɷ� ������ (0,1) ��ġ��, (2,3) �Ǵ��� ������
						}
					}
				}
				int idx = n-1; // ���ʺ��� ä���
				for (int i = tmp_mp.size()-1; i >=0; i--) {	// �������� �о����ϱ� mp ���� �������� tmp_mp�� push�� ��
					if (tmp_mp[i]) {// tmp_mp �� ������
						cp_mp[idx][j] = tmp_mp[i];
						idx--;
					}
				}
			}
		}

		if (dir[k] == 3) {	//��
			for (int j = 0; j < n; j++) {
				vector<int> tmp_mp;
				for (int i = 0; i < n; i++) {	// �ϴ� �ϳ��� �� (��-�� �������� push)
					if (cp_mp[i][j]) {	
						tmp_mp.push_back(cp_mp[i][j]);
						cp_mp[i][j] = 0;
					}
				}
				if (tmp_mp.size() > 1) {
					for (int i = 0; i < tmp_mp.size() - 1; i++) {	// tmp_mp�� ��-�� �������� ��ĥ �� �ִ��� ���� �� ��
						if ((tmp_mp[i] == tmp_mp[i + 1]) && tmp_mp[i] != 0) {
							tmp_mp[i + 1] *= 2;
							tmp_mp[i] = 0;	// ���߿� 0 �ΰ͵��� push ���Ұ�
							i = i + 1;	// 2�� �������ϱ� �״����ɷ� ������ (0,1) ��ġ��, (2,3) �Ǵ��� ������
						}
					}
				}
				/*
				if (tmp_mp.size() > 1) {
					for (int i = tmp_mp.size() - 1; i >= 1; i--) {	// tmp_mp�� ��-�� �������� ��ĥ �� �ִ��� ���� �� ��
						if ((tmp_mp[i] == tmp_mp[i - 1]) && tmp_mp[i] != 0) {
							tmp_mp[i] *= 2;
							tmp_mp[i - 1] = 0;	// ���߿� 0 �ΰ͵��� push ���Ұ�
							i = i - 1;	// 2�� �������ϱ� �״����ɷ� ������ (0,1) ��ġ��, (2,3) �Ǵ��� ������
						}
					}
				}
				*/
				int idx = 0; // ���ʺ��� ä���
				for (int i = 0; i < tmp_mp.size(); i++) {	// �������� �о����ϱ� mp ���� �������� tmp_mp�� push�� ��
					if (tmp_mp[i]) {// tmp_mp �� ������
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