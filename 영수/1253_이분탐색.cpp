#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int n;
vector<int> v;
int ans = 0;

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
	for (int i = 0; i < v.size(); i++) {
		int start = 0;
		int end = n - 1;
		int target = v[i];
		while (start < end) {
			if (i == start) {
				start++;
			}
			if (i == end) {
				end--;
			}
			if (start < end) {
				if (v[start] + v[end] == target) {
					ans ++;
					break;
				}
				if (v[start] + v[end] < target) {
					start++;
				}
				else {
					end--;
				}
			}
		}
	}
	cout << ans << '\n';

}