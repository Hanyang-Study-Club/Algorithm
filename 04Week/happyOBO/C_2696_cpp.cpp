#include <bits/stdc++.h>

using namespace std;

class MedianCalculator
{
	priority_queue<int, vector<int>, less<int>> left; // maxpq
	priority_queue<int, vector<int>, greater<int>> right; // minpq

	queue<int> result;

public:
	void Input(int M)
	{
		int num, mid;
		cin >> num;
		mid = num;
		result.push(mid);
		for (int i = 1; i < M; i++)
		{

			cin >> num;
			if (num < mid)
			{
				left.push(num);
			}
			else
			{
				right.push(num);
			}

			if (i % 2 == 0)
			{
				int left_size = left.size();
				int right_size = right.size();

				if (left_size < right_size)
				{
					left.push(mid);
					left_size++;
				}
				else
				{
					right.push(mid);
					right_size++;
				}

				if (left_size < right_size)
				{
					mid = right.top(); right.pop();
				}
				else
				{
					mid = left.top(); left.pop();
				}
				result.push(mid);
			}
		}
	}

	void Print()
	{
		cout << result.size() << "\n";

		while (!result.empty())
		{
			for (int i = 0; i < 10 && !result.empty(); i++)
			{
				cout << result.front() << " ";
				result.pop();
			}
			cout << "\n";
		}
	}

	void Reset()
	{
		left = priority_queue<int, vector<int>, less<int>>(); // maxpq
		right = priority_queue<int, vector<int>, greater<int>>(); // minpq
		result = queue<int>();
	}

};




int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T, M;
	MedianCalculator mc;

	cin >> T;
	while (T--)
	{
		cin >> M;

		mc.Reset();
		mc.Input(M);
		mc.Print();
	}

	return 0;
}

