#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;	// 숫자 갯수
vector<int> num;
int op[4];// +, - , x, /
int op_check[4];
vector<int> op_v;

long long max_num = -1000000001;
long long min_num = 1000000001;

void sol() {
	//계산 파트
	long long tmp = num[0];
	for (int i = 0; i < op_v.size(); i++) {
		if (op_v[i] == 0) {
			tmp = tmp + num[i + 1];
		}
		if (op_v[i] == 1) {
			tmp = tmp - num[i + 1];
		}
		if (op_v[i] == 2) {
			tmp = tmp * num[i + 1];
		}
		if (op_v[i] == 3) {
			tmp = tmp / num[i + 1];
		}
	}
	max_num = max(max_num, tmp);
	min_num = min(min_num, tmp);

}
void back() {

	if (op_v.size() == num.size() - 1) {
		sol();
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (op_check[i] < op[i]) {
			op_v.push_back(i);
			op_check[i]++;
			back();
			op_check[i]--;
			op_v.pop_back();
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		num.push_back(tmp);
	}
	for (int i = 0; i < 4; i++) {
		cin >> op[i];
	}
	
	back();
	cout << max_num << endl;
	cout << min_num << endl;
}