#include <bits/stdc++.h>
#include <climits>

using namespace std;

// 기본적인 BFS 랑은 조금 다른게
// 최단 거리 뿐만 아니라 위치에 우선 순위가 있다는 것이다.
// 그렇기 때문에 최단 거리를 만족하는 위치를 우선 순위 큐에 모아서
// 어떤 걸 택할지 탐색하는 과정을 추가로 해야한다.


// 함수 파라미터로 넘겨줘야할게 많아져서 class 로 묶음
class BFSSolver
{
	int N;
	vector<vector<int>> dist;
	vector<vector<int>> graph;

	int SharkSize = 2; // 상어 크기
	pair<int, int> SharkPos; // 초기 상어 위치

	int EatenFishCount = 0; // 현재 레벨에서부터 먹은 물고기 수

	int CurrentTime = 0; // 흐른 시간

	// 위쪽, 왼쪽 먼저 탐색
	pair<int, int> Directions[4] = { {-1,0}, {0,-1} , {0, 1}, { 1, 0 }};

	int tmpMinDist = INT_MAX;

	queue<pair<int, int>> q; // 이동 경로 후보 군
	// 물고기 후보군
	priority_queue<pair<int, int>,vector<pair<int,int>>, greater<pair<int,int>>> pq; //min heap

	int bfs(pair<int, int>& start)
	{
		
		dist[start.first][start.second] = 0;
		q.push(start);

		pair<int, int> curr, next;

		while (true)
		{
			while (!q.empty())
			{
				curr = q.front(); q.pop();
				for (pair<int, int>& dir : Directions)
				{
					next = { curr.first + dir.first , curr.second + dir.second };

					if (CanGo(next) && dist[curr.first][curr.second] + 1  <= tmpMinDist)
					{
						dist[next.first][next.second] = dist[curr.first][curr.second] + 1;
						// 바로 먹지 말고, 후보군을 만들고, 하나를 택한다.
						if (CanEatFish(next))
						{
							pq.push(next);
							tmpMinDist = dist[next.first][next.second];
						}
						else
						{
							q.push(next);
						}
					
					}

				}
			}

			if (!pq.empty())
			{
				pair<int, int> pos = pq.top();
				EatFish(pos);
				flush(pos);
				q.push(pos);
				LevelUp();
			}
			else
			{
				break;
			}

		}

		return CurrentTime;

	}

	bool CanGo(pair<int, int>& pos)
	{
		if (pos.first < 0 || N <= pos.first)
			return false;
		if (pos.second < 0 || N <= pos.second)
			return false;
		// 방문한 적이 없고, Fish 레벨이 현재 상어 사이즈보다 작거나 같은 경우
		return dist[pos.first][pos.second] == -1 && graph[pos.first][pos.second] <= SharkSize;
	}

	bool LevelUp()
	{
		if (SharkSize <= EatenFishCount)
		{
			EatenFishCount = 0;
			SharkSize++;
			return true;
		}

		return false;
	}

	bool CanEatFish(pair<int, int>& pos)
	{
		return 0 < graph[pos.first][pos.second] && graph[pos.first][pos.second] < SharkSize;
	}

	void EatFish(pair<int, int> pos)
	{
		EatenFishCount++; // 먹은 물고기 추가
		CurrentTime += dist[pos.first][pos.second]; // 물고기 먹을때까지 이동 시간 추가
	}

	void flush(pair<int, int> pos)
	{
		graph[pos.first][pos.second] = 0; // 먹었으니 물고기 삭제
		tmpMinDist = INT_MAX;
		dist = vector<vector<int>>(N, vector<int>(N, -1)); // 먹었으니 왔던곳 다시 가도 된다.
		dist[pos.first][pos.second] = 0;
		q = queue<pair<int, int>>(); // 위치 담던 큐도 초기화
		pq = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>();
	}


public:

	void Input()
	{
		cin >> N;

		graph.resize(N, vector<int>(N));
		dist.resize(N, vector<int>(N, -1));

		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < N; x++)
			{
				cin >> graph[y][x];
				if (graph[y][x] == 9) // 아기 상어~ 
				{
					SharkPos = { y, x };
					graph[y][x] = 0;
				}
			}
		}
	}

	void solve()
	{
		cout << bfs(SharkPos);
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

