#include <bits/stdc++.h>
#include <climits>

using namespace std;

// 함수 파라미터로 넘겨줘야할게 많아져서 class 로 묶음
class BFSSolver
{
	int N;
	int M;
	vector<vector<bool>> visited;

	pair<int, int> Directions[4] = { {0,1}, {0,-1}, {1, 0}, {-1, 0} };

	int bfs(pair<int, int>& start)
	{
		int counter = 0;
		queue<pair<int, int>> q;

		visited[start.first][start.second] = true;
		q.push(start);
		counter++;

		pair<int, int> curr, next;
		while (!q.empty())
		{
			curr = q.front(); q.pop();
			for (pair<int, int>& dir : Directions)
			{
				next = { curr.first + dir.first , curr.second + dir.second };

				if (CanGo(next))
				{
					visited[next.first][next.second] = true;
					q.push(next);
					counter++;
				}

			}
		}
		return counter;

	}

	bool CanGo(pair<int, int>& pos)
	{
		if (pos.first < 0 || M <= pos.first)
			return false;
		if (pos.second < 0 || N <= pos.second)
			return false;
		return !visited[pos.first][pos.second];
	}

public:

	void Input()
	{
		int K;
		cin >> M >> N >> K;

		visited.resize(M, vector<bool>(N, false));

		pair<int, int> left_bottom, right_up;
		for (int i = 0; i < K; i++)
		{
			cin >> left_bottom.second >> left_bottom.first >> right_up.second >> right_up.first;

			for (int y = left_bottom.first; y < right_up.first; y++)
			{
				for (int x = left_bottom.second; x < right_up.second; x++)
				{
					visited[y][x] = true;
				}
			}
		}
	}

	void solve()
	{
		vector<int> areas;
		pair<int, int> start;
		for (int y = 0; y < M; y++)
		{
			for (int x = 0; x < N; x++)
			{
				start = { y,x };
				if (CanGo(start))
				{
					areas.push_back(bfs(start));
				}
			}
		}

		sort(areas.begin(), areas.end());
		cout << areas.size() << "\n";
		for (int area : areas)
			cout << area << " ";
	}

};




int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	BFSSolver BS;
	BS.Input();
	BS.solve();

	return 0;
}

