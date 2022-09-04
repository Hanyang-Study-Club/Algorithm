#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

const long long LLTERM = 1000000000000000000;
const int MAXSIZE = 100001;
const int NUMMAXSIZE = 1200;
struct BigNum
{
	int size;
	long long LastTermData;


};

BigNum fibo[MAXSIZE] = {};

void CalcFibo()
{
	long long tmp[3][NUMMAXSIZE] = {};
	int curr, prev1, prev2;
	// init
	fibo[0].size = 0;
	fibo[0].LastTermData = 0;
	fibo[1].size = 1;
	fibo[1].LastTermData = 1;

	tmp[1][0] = 1;


	for (int i = 2; i < MAXSIZE; i++)
	{
		// 다음 탐색 때는 curr --> prev1 , prev1 --> prev2 인덱스로 넘어감
		curr = i % 3;
		prev1 = (i - 1) % 3;
		prev2 = (i - 2) % 3;

		// LLTERM 보다 크면 다음 배열 값을 1추가해서 넘겨버린다.
		long long acc = 0;
		for (int j = 0; j < fibo[i - 1].size; j++)
		{
			acc += tmp[prev1][j] + tmp[prev2][j];
			if (LLTERM <= acc) // 올림 처리
			{
				tmp[curr][j] = acc - LLTERM;
				acc = 1;
			}
			else
			{
				tmp[curr][j] = acc;
				acc = 0;
			}
		}
		tmp[curr][fibo[i - 1].size] = acc;
		if (acc == 0) fibo[i].size = fibo[i - 1].size;
		else fibo[i].size = fibo[i - 1].size + 1;
		fibo[i].LastTermData = tmp[curr][fibo[i].size - 1];

	}
}

int BinarySearch(BigNum& target)
{
	int start = 0;
	int end = MAXSIZE;
	int mid;

	while (start <= end)
	{
		mid = (start + end) / 2;
		if (fibo[mid].size == target.size && fibo[mid].LastTermData == target.LastTermData)
		{
			return mid;
		}
		else if (fibo[mid].size < target.size ||
			(fibo[mid].size == target.size && fibo[mid].LastTermData < target.LastTermData))
		{
			start = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
	}

	return -1;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	char num[21010] = {};

	BigNum BG;
	CalcFibo();
	while (N--)
	{
		cin >> num;
		int len = strlen(num);
		long long acc = 0;

		for (int i = 0; i < (len - 1) % 18 + 1; i++)
		{
			acc = acc * 10 + (num[i] - '0');
		}
		if (acc == 1 && len == 1)
		{
			cout << 2 << "\n";

		}
		else
		{
			int LastTermIdx = len / 18;
			if (len % 18 > 0) LastTermIdx++;

			BG.size = LastTermIdx;
			BG.LastTermData = acc;
			cout << BinarySearch(BG) << "\n";
		}

	}

	return 0;
}

