#include <bits/stdc++.h>
#include <climits>

using namespace std;


void bfs(int start, vector<bool>& visited, vector<vector<int>>& graph)
{
	queue<int> q;

	visited[start] = true;
	q.push(start);

	int curr, next;
	while (!q.empty())
	{
		curr = q.front(); q.pop();
		for (int next : graph[curr])
		{
			if (!visited[next])
			{
				q.push(next);
				visited[next] = true;
			}
		}

	}

}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	vector<vector<int>> graph;
	vector<bool> visited;

	int N, M;
	cin >> N >> M;
	
	graph.resize(N);
	visited.resize(N, false);

	int v1, v2;
	for (int i = 0; i < M; i++)
	{
		// 양방향
		cin >> v1 >> v2;
		graph[v1 - 1].push_back(v2 - 1);
		graph[v2 - 1].push_back(v1 - 1);

	}

	// 정점에서부터 시작해서 bfs 탐색을 하되
	// 이전에 방문 했다면 skip
	// 아니라면 카운트 + 1
	int counter = 0;
	for (int i = 0; i < N; i++)
	{
		if (!visited[i])
		{
			counter++;
			bfs(i, visited, graph);
		}
	}


	cout << counter;

	return 0;
}

