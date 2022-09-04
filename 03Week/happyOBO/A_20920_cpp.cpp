#include <bits/stdc++.h>

using namespace std;

struct RememberWord {

	struct Comparer
	{
		constexpr bool operator()(const pair<string, int>& _Left, const pair<string, int>& _Right) const {
			// 1. 자주 나오는 단어일수록 앞에 배치한다.
			if (_Left.second != _Right.second)
				return _Left.second < _Right.second;
			// 2. 해당 단어의 길이가 길수록 앞에 배치한다.
			if (_Left.first.size() != _Right.first.size())
				return _Left.first.size() < _Right.first.size();
			// 3. 알파벳 사전 순으로 앞에 있는 단어일수록 앞에 배치한다
			return _Left.first > _Right.first;
		}
	};

	unordered_map<string, int> um;
	priority_queue < pair<string, int>, vector<pair<string, int>>, Comparer> pq;

	void GetInput(int N, int M)
	{
		string word;
		for (int i = 0; i < N; i++)
		{
			cin >> word;
			if (word.size() < M)
				continue;

			if (um.find(word) == um.end())
			{
				um.insert({ word, 1 });
			}

			else
			{
				um[word]++;
			}

		}
	}

	void Solve()
	{
		for (auto& w : um)
		{
			pq.push(w);
		}

		while (!pq.empty())
		{
			cout << pq.top().first << "\n";
			pq.pop();
		}

	}

};

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	
	cin >> N >> M;
	
	RememberWord rw = RememberWord();

	rw.GetInput(N, M);
	rw.Solve();

	return 0;
}