#include <bits/stdc++.h>

using namespace std;


void solution(int N, int X, vector<vector<int>>& graph);
void dijkstra(int start, int N, vector<vector<int>>& graph);
void dijkstra_reverse(int start, int N, vector<vector<int>>& graph);
const int MAXSIZE = 1001;
int dist[MAXSIZE] = {};
int dist_reverse[MAXSIZE] = {};

int main() {
	int N, M, X;
	cin >> N >> M >> X;
	vector<vector<int>> graph(N+1,vector<int>(N+1,INT_MAX));
	for (int i = 0; i < M; i++)
	{
		int start, end, w;
		cin >> start >> end >> w;
		graph[start][end] = w;
	}
	solution(N, X, graph);
}


void solution(int N,int X, vector<vector<int>>& graph)
{
	// 다른 지역 -> X 로 가는 경우
	fill(&dist_reverse[0], &dist_reverse[MAXSIZE], INT_MAX);
	dijkstra_reverse(X, N, graph);

	// X -> 다른 지역으로 가는 경우
	fill(&dist[0], &dist[MAXSIZE], INT_MAX);
	dijkstra(X, N, graph);

	int result = INT_MIN;
	for (int i = 1; i <= N; i++)
	{
		if (i == X) continue;
		if (dist[i] == INT_MAX || dist_reverse[i] == INT_MAX) continue;
		result = max(result, dist[i] + dist_reverse[i]);
	}

	cout << result;
}

void dijkstra(int start, int N, vector<vector<int>>& graph)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, start });
	dist[start] = 0;

	while (!pq.empty())
	{
		int currWeight = pq.top().first;
		int currIdx = pq.top().second;
		pq.pop();

		if (dist[currIdx] < currWeight) continue;

		for (int nextIdx = 1; nextIdx <= N; nextIdx++)
		{
			if (graph[currIdx][nextIdx] == INT_MAX) continue;
			int nextWeight = currWeight + graph[currIdx][nextIdx];
			if (nextWeight < dist[nextIdx])
			{
				pq.push({ nextWeight, nextIdx });
				dist[nextIdx] = nextWeight;
			}

		}
	}
}

void dijkstra_reverse(int end, int N, vector<vector<int>>& graph)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, end });
	dist_reverse[end] = 0;

	while (!pq.empty())
	{
		int currWeight = pq.top().first;
		int currIdx = pq.top().second;
		pq.pop();
		if (dist_reverse[currIdx] < currWeight) continue;

		for (int nextIdx = 1; nextIdx <= N; nextIdx++)
		{
			if (graph[nextIdx][currIdx] == INT_MAX) continue;
			int nextWeight = currWeight + graph[nextIdx][currIdx];
			if (nextWeight < dist_reverse[nextIdx])
			{
				pq.push({ nextWeight, nextIdx });
				dist_reverse[nextIdx] = nextWeight;
			}

		}
	}
}