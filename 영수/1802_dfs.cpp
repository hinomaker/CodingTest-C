#include <iostream>
#include <vector>
#include <string>
using namespace std;

int t;
vector<int> v;
string s;
bool check = true;

void sol(int start, int end) {	// end���� ������ index
	// mid �� ����� �� ... (start, end)�� �ϸ� �Ǽ� ����..!
	int mid = (start + end) / 2;
	if (start < end) {
		for (int i = start; i < mid; i++) {
			if (v[i] == v[end - (i - start)]) {
				check = false;
				return;
			}
		}
		sol(start, mid - 1);
		sol(mid + 1, end);
	}
}


int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> s;
		check = true;
		if (s.size() % 2) {	// Ȧ���϶��� ���� ����
			for (int j = 0; j < s.size(); j++) {
				v.push_back(s[j] - '0');
			}
			sol(0, s.size() - 1);	// ���� dfs�� Ž��
			if (check == true) {
				cout << "YES" << '\n';
			}
			if (check == false) {
				cout << "NO" << '\n';
			}
			while (v.size()) {	// testcase 1ȸ ������ ���� Pop
				v.pop_back();
			}
		}
		else {	// ¦����� NO
			cout << "NO" << '\n';
		}
	}
}