#include <bits/stdc++.h>
using namespace std;

// 백트래킹으로 현재 탐색한 치킨집들로 얻을 수 있는 최단거리 탐색

class ChickenOptimizer
{
public:

	void Input()
	{
		cin >> N >> M;
		int field;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> field;
				if (field == 0) continue;
				else if (field == 1) homes.push_back({ i,j });
				else chickens.push_back({ i,j });
			}
		}
	}

	void Solve()
	{
		vector<int> pick_chickens;
		backtrk(M, 0, pick_chickens);
		cout << min_dist;
	}

protected:

	vector<pair<int, int>> homes;
	vector<pair<int, int>> chickens;

	int N;
	int M;
	int min_dist = INT_MAX;
	
protected:

	void backtrk(int M, int curr, vector<int>& pick_chickens)
	{
		static auto CalcDist = [](pair<int, int> a, pair<int, int> b) { return abs(a.first - b.first) + abs(a.second - b.second);  };
		if (pick_chickens.size() == M)
		{
			int sum_dist, dist;
			sum_dist = 0;
			for (auto& home : homes)
			{
				dist = INT_MAX;
				for (int pc : pick_chickens)
				{
					dist = min(dist, CalcDist(chickens[pc], home));
				}
				sum_dist += dist;
			}
			min_dist = min(min_dist, sum_dist);
		}
		else if (curr == chickens.size())
		{
			return;
		}

		else
		{
			pick_chickens.push_back(curr);
			backtrk(M, curr + 1, pick_chickens);
			pick_chickens.pop_back();
			backtrk(M, curr + 1, pick_chickens);

		}
	}


};




int main()
{
	ChickenOptimizer co;
	co.Input();
	co.Solve();
}

