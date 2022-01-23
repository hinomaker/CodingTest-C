#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int n;
int k;

int main() {
	cin >> n >> k;
	// n개 중 k개 집중국
	// 구간 갯수 : n-1 개 중 (n-k)개 선택(거리 낮은순)

	vector<int> v;	// 각 구간 저장
	vector<int> sub;	// 각 구간 사이 거리
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size() - 1; i++) {
		//cout << v[i] << " ";
//		cout << v[i + 1] - v[i] << " ";
		sub.push_back(v[i + 1] - v[i]);
	}
	//	cout << endl;
	sort(sub.begin(), sub.end());	// 구간 사이거리 정렬
	int cnt = 0;
	int ans = 0;
	if (n <= k) {
		cout << ans;
	}
	else {
		for (int i = 0; i < n - k; i++) {
			ans += sub[i];
		}
		cout << ans << '\n';
	}

}