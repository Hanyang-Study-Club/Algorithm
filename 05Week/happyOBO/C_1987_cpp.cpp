#include <bits/stdc++.h>

using namespace std;

class AlphavetTracker
{
	const static int MAX_SIZE = 21;

	char board[MAX_SIZE][MAX_SIZE] = {};
	bool visited_board[MAX_SIZE][MAX_SIZE] = {};
	bool visited_alphavet['Z' - 'A' + 1] = {};

	int max_dist = INT_MIN;

	pair<int, int> Directions[4] = { {1,0}, {-1,0}, {0,1}, {0,-1} };

	int N, M;

	
public:

	void Input()
	{
		cin >> N >> M;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				cin >> board[i][j];
			}
		}
	}


	void Solution()
	{
		pair<int, int> curr = {0,0};
		
		visited_board[curr.first][curr.second] = true;
		visited_alphavet[board[curr.first][curr.second] - 'A'] = true;

		backtrk(1, curr);
		
		cout << max_dist;
	}

protected:

	void backtrk(int dist, pair<int, int>& curr)
	{
		bool no_way = true;

		for (auto& dir : Directions)
		{
			pair<int, int> next = { curr.first + dir.first, curr.second + dir.second };
			if(!CanGo(next)) continue; // 인덱스를 넘어선 자리
			if(visited_board[next.first][next.second] == true) continue; // 이미 방문한 자리
			if (visited_alphavet[board[next.first][next.second] - 'A'] == true) continue; // 이미 방문한 알파벳

			visited_board[next.first][next.second] = true;
			visited_alphavet[board[next.first][next.second] - 'A'] = true;

			backtrk(dist + 1, next);

			visited_board[next.first][next.second] = false;
			visited_alphavet[board[next.first][next.second] - 'A'] = false;

		}

		if (no_way)
		{
			max_dist = max(dist, max_dist);
		}

	}

	bool CanGo(pair<int, int>& curr)
	{
		if (curr.first < 0 || N <= curr.first )
			return false;
		if (curr.second < 0 || M <= curr.second )
			return false;

		return true;
	}

};


int main()
{
	AlphavetTracker at;

	at.Input();
	at.Solution();

}

