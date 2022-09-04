#include <bits/stdc++.h>

using namespace std;

const int MAXSIZE = 10001;

// dp[i] : i 원을 만들 수 있는 방법의 수
int dp[MAXSIZE] = {};

void solution(int K, vector<int>& coins)
{
	
	for (auto coin : coins)
	{
		for (int i = coin; i <= K; i++)
		{
			if (i == coin) dp[i] += 1;
			else dp[i] += dp[i - coin]; // dp[i] = ( i - 탐색하는 동전 가치) 경우의 수의 합
		}
	}

	cout << dp[K];

}

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, K;

	cin >> N >> K;

	vector<int> coins(N);
	for (int i = 0; i < N; i++)
	{
		cin >> coins[i];
	}

	solution(K, coins);
}
