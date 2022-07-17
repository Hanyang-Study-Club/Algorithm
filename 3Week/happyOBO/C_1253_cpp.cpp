#include <bits/stdc++.h>

using namespace std;

class GoodFinder
{
	vector<int> numbers;
	map<int, int> frequency;
	map<int, int> result;
	int counter = 0;
public:
	void GetInput(int N)
	{
		int num;
		for (int i = 0; i < N; i++)
		{
			cin >> num;

			numbers.push_back(num);

			if (frequency.find(num) == frequency.end())
			{
				frequency.insert({ num, 0});
				result.insert({ num, 0 });
			}

			frequency[num]++;
			result[num]++;
		}
	}

	void Solve()
	{
		finder();
	}

	void Print()
	{
		cout << counter;
	}

private:
	void finder()
	{
		int sum, a, b;
		// a + b == a 라면
		// a 가 아닌 a 값을 지닌 숫자가 더 있는 지 확인
		for (int i = 0; i < numbers.size(); i++)
		{
			a = numbers[i];
			for (int j = i + 1; j < numbers.size(); j++)
			{
				b = numbers[j];
				sum = a + b;
				auto goodCandidates = result.find(sum);

				if(goodCandidates == result.end() || goodCandidates->second <= 0)
					continue;

				if (sum == a || sum == b)
				{

					// a + b == a 인 경우 || 0 + 0 == 0 인 경우
					if (a == 0 && b == 0)
					{
						if (2 < frequency[sum])
						{
							counter++;
							goodCandidates->second--;
						}
					}
					else if (1 < frequency[sum])
					{
						counter++;
						goodCandidates->second--;
					}
				}

				else
				{
					counter += goodCandidates->second;
					goodCandidates->second = 0;
				}

				
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

	GoodFinder cc;
	cc.GetInput(N);
	cc.Solve();
	cc.Print();


	return 0;
}