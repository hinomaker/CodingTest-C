#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int n;
int b;
int c;
vector<int> v;
int ans;

void sol() {
	for (int i = 0; i < n; i++) {
		v[i] -= b;	// b�� �� �������� ���� �������� �ΰ������� ����
		ans++;	// �Ѱ����� 1��
		if (v[i]%c != 0 && v[i] > 0) {
			ans += (v[i] / c +1);	// �ΰ������� Ŀ�� �� �� �ִ� ��ü
		}
		if (v[i] % c == 0 && v[i] > 0) {
			ans += v[i] / c;
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	cin >> b >> c;
	sol();
	cout << ans << endl;
}