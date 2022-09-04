#include <bits/stdc++.h>

using namespace std;

const int MAXSIZE = 501;

// dp[i][j] : 행렬 i ~ j번째 까지 곱했을 때 올 수 있는 최소 연산 개수
int dp[MAXSIZE][MAXSIZE] = {};

void solution(int N, vector<pair<int,int>>& matrixes)
{
	// 바로 연속된 행렬과의 연산 수 계산
	for (int i = 0; i < N - 1; i++)
	{
		dp[i][i + 1] = matrixes[i].first * matrixes[i].second * matrixes[i + 1].second;
	}

	for (int term = 2; term < N; term++)
	{
		for (int i = 0; i < N - term; i++)
		{
			int j = i + term;
			// dp[i][j] = [i ~ k 까지의 행렬 최소 연산] + [k + 1 ~ j 까지의 행렬 최소 연산] + [두 행렬의 연산 수]
			// k 는 i ~ j 사잇값
			dp[i][j] = INT_MAX;
			for (int k = i; k < j; k++)
			{
				dp[i][j] = min(dp[i][j]
							,  dp[i][k] + dp[k + 1][j] + matrixes[i].first * matrixes[k].second * matrixes[j].second);
			}

		}


	}

	cout << dp[0][N - 1];
}

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;

	cin >> N;

	vector<pair<int, int>> matrixes(N);

	for (int i = 0; i < N; i++)
	{
		cin >> matrixes[i].first >> matrixes[i].second;
	}

	solution(N, matrixes);
}
