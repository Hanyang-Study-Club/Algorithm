#include <bits/stdc++.h>

using namespace std;

class CardCollector
{
	vector<int> cards;
	set<int> result;

	int MAX = 0;

public:
	void GetInput(int N)
	{
		int num;
		for (int i = 0; i < N; i++)
		{
			cin >> num;

			cards.push_back(num);
			result.insert(num);
			MAX += num;
		}
	}

	void Solve()
	{
		backtrk(0,0);
	}

	void Print()
	{
		cout << MAX - result.size() + 1;
	}

private:
	void backtrk(int curr, int sum)
	{
		result.insert(sum);

		if (cards.size() <= curr)
			return;
		backtrk(curr + 1, sum + cards[curr]);
		backtrk(curr + 1, sum);

	}

};

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	
	cin >> N;

	CardCollector cc;
	cc.GetInput(N);
	cc.Solve();
	cc.Print();


	return 0;
}