#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> container;
vector<int> answer_vector;

/*
기존 수열을 정렬하지 않고 기존 것 그대로 상태에서 증가하는 부분수열을 찾아야함!(중요)
*/

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, answer = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int number = 0;
		cin >> number;

		container.push_back(number);
	}

	answer_vector.push_back(container[0]);
	for (int i = 1; i < n; i++) {
		// 왜 등호를 넣어야 하는것인가......................? 왜지 왜 안 넣으면 틀리지 왜지 왜 때문이지 왜지 왜일까
		/*
		알았다. 안 넣으면 등호가 else에 걸려서 같은 것이 나올 경우 무조건 vector에 push해버림. 그래서 등호처리를 위의 if에서 같이 함. 아니면 그냥 else를 if로 바꿔도 될듯? ㅇㅇ 됨 :)
		*/

		if (answer_vector[answer_vector.size() -1] > container[i]) {
			int insert_index = lower_bound(answer_vector.begin(), answer_vector.end(), container[i]) - answer_vector.begin();
			answer_vector[insert_index] = container[i];
		}
		if(answer_vector[answer_vector.size() - 1] < container[i]) answer_vector.push_back(container[i]);
	}

	cout << answer_vector.size() << '\n';
	return 0;
}
