#include <bits/stdc++.h>
#include <climits>

using namespace std;


class MooSolver
{
	// S(k) = S(k-1) + ['m' + 'o' * (k+2)] + S(k-1)
	// L(k) = S(k)의 길이라고 할 때
	// L(k) = 2 * L(k-1) + k + 3
	// 현재 탐색하고 있는 target 이 ['m' + 'o' * (k+2)] 에 해당할때까지 devide

	char s_0[3] = {'m', 'o', 'o'};

	char result = '\0';

	// target : 목표 문자열 인덱스 값
	// k : 몇 번째 수열 탐색 중인지
	// length : 현재 탐색하고 있는 길이
	void devide(int target, int k, int length)
	{

		int new_length = length * 2 + k + 3;
		if (result) return;

		if (target <= 3)
		{
			result = s_0[target - 1];
			return;
		}
		if (new_length < target) // n이 다음 길이 보다 커지기 직전까지의 k 값 및 길이 탐색.
		{
			devide(target, k + 1, new_length);
		}
		else
		{
			// target 이 'm' + 'o' * (k+2) 에 속하면 result 겟
			if ( length < target && target <= length + k + 3) {
				if (target - length != 1)
					result = 'o';
				else
					result = 'm';
				return;
			}
			else {
				// S(k-1) 부분에 속한다면, S(k-1) 부분에 대해서 다시 계산 시작.
				devide(target - (length + k + 3), 1, 3);
			}
		}
	}

public:
	char solve(int N)
	{
		devide(N, 1, 3);
		return result;
	}

};

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	MooSolver ms;
	cout << ms.solve(N);

}

