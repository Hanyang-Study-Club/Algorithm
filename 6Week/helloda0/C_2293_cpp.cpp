#include<iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	int narr[101];
	int dp[10001] = { 0 };
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> narr[i];
	}

	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = narr[i]; j <= k; j++) {
			dp[j] += dp[j - narr[i]];
		}
	}

	cout << dp[k];

	return 0;
}