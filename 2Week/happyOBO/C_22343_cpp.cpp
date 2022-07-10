#include <bits/stdc++.h>

using namespace std;

class BracketCalculator
{
public:
	BracketCalculator(string data, int size)
	{

		result = vector<int>(size, 0);
		Calc(data);
	}

public:
	vector<int> result;

	static void Compare(BracketCalculator& A, BracketCalculator& B)
	{
		for (int i = A.result.size() -1; 0 <= i ; i--)
		{
			if (A.result[i] > B.result[i])
			{
				cout << ">" << "\n";
				return ;
			}
			else if (A.result[i] < B.result[i])
			{
				cout << "<" << "\n";
				return;
			}
		}
		cout << "=" << "\n";
	}

private:
	// 진수 깊이(누적 '(' 수) 를 나타냄.
	int cursor = 0;

	void Calc(string data)
	{
		for(int i = 0; i < data.size(); i++)
		{
			if (data[i] == '(')
			{
				// 진수 깊이 증가
				cursor++;
			}
			else
			{
				// 진수 깊이 감소
				cursor--;
				if (data[i - 1] == '(')
				{
					// () == 1
					result[cursor]++;
				}
			}
		}

		MakeBinary();
	}

	void MakeBinary()
	{
		for (int i = 0; i < result.size()-1; i++)
		{
			result[i + 1] += result[i] / 2;
			result[i] %= 2;
		}
	}

};

int main() {
	int N, size;
	string A;
	string B;

	cin >> N;
	while (N--)
	{
		cin >> A;
		cin >> B;

		// 진수 최대 깊이 (data 절반) 까지 가능
		size = max(A.size(), B.size()) / 2 + 1;

		BracketCalculator BA = BracketCalculator(A,size);
		BracketCalculator BB = BracketCalculator(B,size);

		BracketCalculator::Compare(BA, BB);

	}
	return 0;
}