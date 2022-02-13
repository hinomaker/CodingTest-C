#include <iostream>

using namespace std;


int dp[31];

int main() {
	dp[0] = 1;//¿¹¿Ü
	dp[2] = 3;
	int n;
	cin >> n;
	for (int i = 4; i <= n; i= i * 2) {
		dp[i] = dp[2]*dp[i - 2];
		for (int j = i - 2; j >= 0; j /= 2) {
			dp[i] += 2 * dp[j];
		}
	}
	cout << dp[n];

	
	


}