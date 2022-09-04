#include <bits/stdc++.h>
#include <climits>

using namespace std;


class TeamOptimizer
{
	static const int MAXSIZE = 21;
	
	int _arr[MAXSIZE][MAXSIZE] = {};
	bool _is_start[MAXSIZE] = {};
	int _result = INT_MAX;
	int _size;

public:
	void Input(int N) 
	{
		_size = N;
		for (int i = 0; i < _size; i++)
		{
			for (int j = 0; j < _size; j++)
			{
				cin >> _arr[i][j];
			}
		}
	}

	void Solve()
	{
		backtrk(0, 0);
	}

	void Print()
	{
		cout << _result;
	}

protected:
	void backtrk( int idx, int start_counter)
	{
		if (start_counter == _size / 2)
		{
			int start_team_power , link_team_power;
			start_team_power = link_team_power = 0;
			// 링크 점수 계산
			for (int i = 0; i < _size; i++)
			{
				for (int j = 0; j < _size; j++)
				{
					if (_is_start[i] && _is_start[j]) start_team_power += _arr[i][j];
					else if (!_is_start[i] && !_is_start[j]) link_team_power += _arr[i][j];
				}
			}
			_result = min(_result, abs(link_team_power - start_team_power));

			return;
		}
		else
		{
			for (int i = idx; i < _size; i++)
			{
				_is_start[i] = true;
				backtrk(i + 1, start_counter + 1);
				_is_start[i] = false;
			}
		}

	}

};



int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	TeamOptimizer to;

	to.Input(N);
	to.Solve();
	to.Print();

	return 0;
}

