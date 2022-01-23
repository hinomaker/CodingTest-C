#include <iostream>
#include <vector>
#include <string>
using namespace std;

int t;
vector<int> v;
string s;
bool check = true;

void sol(int start, int end) {	// end점은 마지막 index
	// mid 값 사용할 것 ... (start, end)로 하면 실수 있음..!
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
		if (s.size() % 2) {	// 홀수일때만 진행 가능
			for (int j = 0; j < s.size(); j++) {
				v.push_back(s[j] - '0');
			}
			sol(0, s.size() - 1);	// 조건 dfs로 탐색
			if (check == true) {
				cout << "YES" << '\n';
			}
			if (check == false) {
				cout << "NO" << '\n';
			}
			while (v.size()) {	// testcase 1회 끝나고 벡터 Pop
				v.pop_back();
			}
		}
		else {	// 짝수라면 NO
			cout << "NO" << '\n';
		}
	}
}