#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> container_vector;
map<int, int> container_map;

/*
1.  map을 이용하여 하나씩 찾는 거 -> 시간초과
2. 일반적인 이분탐색 -> 시간초과
3. lower_bound, upper_bound 사용
4. 둘 중 하나만 사용했을 경우 시간초과
5. 둘이 같이 사용.

upper_bound ->  삽입 될 수 있는 위치 중 가장 큰 인덱스.
lower_bound -> 삽입 될 수 있는 위치 중 가장 작은 인덱스.
*/

void solution(int a) {
	for (int i = 0; i < a; i++) {
		int find_number = 0;
		cin >> find_number;

		// 오름차순으로 정렬하였으니 upper_bonund사용 
		int upper_index = upper_bound(container_vector.begin(), container_vector.end(), find_number) - container_vector.begin();
		int lower_index = lower_bound(container_vector.begin(), container_vector.end(), find_number) - container_vector.begin();
		// a를 처음으로 초과하는 인덱스 번호가 나옴. 

		cout << upper_index - lower_index << " ";
	}
	cout << '\n';
}

void input() {
	int n = 0, m = 0;
	cin >> n;

	// 1. 넣기.
	for (int i = 0; i < n; i++) {
		int number = 0;
		cin >> number;

		container_vector.push_back(number);
	}

	sort(container_vector.begin(), container_vector.end());

	cin >> m;
	solution(m);
}

void solve() {
	input();
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();

	//vector<int> a = { 1,2,2,3,3,4,4,6,6,8,8,9 }; // 11개
	//cout << upper_bound(a.begin(), a.end(), 12) - a.begin() << endl; // 12
	return 0;
}
