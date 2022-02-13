#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int m;
vector<int> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	cin >> m;
	for (int i = 0; i < m; i++) {
		int tmp;
		cin >> tmp;
		auto up = upper_bound(v.begin(), v.end(), tmp);
		auto low = lower_bound(v.begin(), v.end(), tmp);
		cout << up - low << " ";
	}

}