#include <bits/stdc++.h>

using namespace std;

void solution(int N, vector<pair<pair<int, int>, pair<int, int>>>& inputs);

const int MAXSIZE = 1025;
int graph[MAXSIZE][MAXSIZE] = {};
int acc[MAXSIZE][MAXSIZE] = {};


int main()
{
	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> graph[i][j];
		}
	}

	vector<pair<pair<int, int>, pair<int, int>>> inputs(M);
	for (int i = 0; i < M; i++)
	{
		cin >> inputs[i].first.first >> inputs[i].first.second >> inputs[i].second.first >> inputs[i].second.second;
	}

	solution(N, inputs);
}

void solution(int N, vector<pair<pair<int,int>, pair<int,int>>>& inputs)
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			acc[i][j] = graph[i][j] +
						acc[i - 1][j] +
						acc[i][j - 1] -
						acc[i - 1][j - 1];
		}
	}

	for (auto& input : inputs)
	{
		auto& p1 = input.first;
		auto& p2 = input.second;
		cout << acc[p2.first][p2.second] -
				acc[p2.first][p1.second - 1] -
				acc[p1.first - 1][p2.second] +
				acc[p1.first - 1][p1.second - 1] << "\n";
	}
}

