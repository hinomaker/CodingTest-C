#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> container;

// 하나의 수가 해당 수가 아닌 다른 수2개의 합으로 이뤄질 경우 좋은 수.

int main(void) {
	int n, answer = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int number = 0;
		cin >> number;

		container.push_back(number);
	}
	sort(container.begin(), container.end());
	// 오름차순 정렬.


	for (int i = 0; i < n; i++) {
		// 알고 싶은 것은 container[i]가 좋은 수 인지 아닌지 -> 그럼 container[start]나 container[end]가 container[i]가 되서는 안된다.(문제 조건)

		int start = 0, end = n - 1;
		while (start < end) {
			if (start == i) {
				start++;
				continue;
			}
			if (end == i) {
				end--;
				continue;
			}

			// 두 포인터의 합이 현재 수보다 왼쪽에 있다면? start를 늘려가며 하나씩 이동해야 하며,애초에 end는 오른쪽으로 이동이 불가능함.
			if (container[start] + container[end] < container[i]) {
				start++;
				continue;
			}
			else if (container[start] + container[end] > container[i]) {
				// 마찬가지로 두 포인터의 합이 현재 수보다 오른쪽에 있다면, start는 그대로 두고, end를 1씩 감소시키며 현재 수와 비교.
				end--;
				continue;
			}
			else {
				// 좋은 수일 경우
				answer++;
				break;
			}
		}
	}
	cout << answer << '\n';
	return 0;
}
