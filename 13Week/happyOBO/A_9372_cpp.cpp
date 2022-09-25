#include <bits/stdc++.h>
#include <climits>

using namespace std;

void bfs(vector<vector<int>>& graph)
{
	vector<bool> visited(graph.size(), false);

	queue<int> q;

	q.push(0);
	visited[0] = true;

	int counter = 0;

	int curr;
	while (!q.empty())
	{
		curr = q.front(); q.pop();

		for (auto next : graph[curr])
		{
			if (!visited[next])
			{
				visited[next] = true;
				q.push(next);
				counter++;
			}
		}
	}

	cout << counter << "\n";
}

int main()
{
	int T, N, M;
	
	cin >> T;

	while (T--)
	{
		cin >> N >> M;

		vector<vector<int>> graph(N);

		int n1, n2;
		for (int i = 0; i < M; i++)
		{
			cin >> n1 >> n2;
			graph[n1 - 1].push_back(n2 - 1);
			graph[n2 - 1].push_back(n1 - 1);
		}

		bfs(graph);
	}


}

