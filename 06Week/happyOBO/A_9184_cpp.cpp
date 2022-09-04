#include <bits/stdc++.h>

using namespace std;

const int MAXSIZE = 110;
int MID = 50;
// dp[MID + a][MID + b][MID + c] : w(a,b,c) 계산 값
int dp[MAXSIZE][MAXSIZE][MAXSIZE] = {};

int w(int a, int b, int c)
{
	if (dp[MID + a][MID + b][MID + c] != INT_MIN)
		return dp[MID + a][MID + b][MID + c];
	else if ( a <= 0 || b <= 0 || c <= 0)
		return dp[MID + a][MID + b][MID + c] = 1;
	else if (a > 20 || b > 20 || c > 20)
		return dp[MID + a][MID + b][MID + c] = w(20,20,20);
	else
	{
		return dp[MID + a][MID + b][MID + c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
	}
}

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	for (int i = 0; i < MAXSIZE; i++)
	{
		for (int j = 0; j < MAXSIZE; j++)
		{
			for (int k = 0; k < MAXSIZE; k++)
			{
				dp[i][j][k] = INT_MIN;
			}
		}
	}

	int a, b, c;

	while (true)
	{
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1)
		{
			break;
		}

		w(a, b, c);
		cout << "w("<< a << ", "<< b <<", "<< c <<") = " << dp[MID + a][MID + b][MID + c] <<"\n";
	}


}

