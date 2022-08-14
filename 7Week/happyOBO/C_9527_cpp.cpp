#include <bits/stdc++.h>

using namespace std;

const int MAXSIZE = 60; // 10^16 => 2^4 * (1024)^5 => 2^60

long long powsum[MAXSIZE] = {}; // powsum[k] = 2^k -1 까지 등장하는 총 1의 개수

void makePowSum()
{
	powsum[0] = 1;
	for (int i = 1; i <= MAXSIZE; i++)
	{
		powsum[i] = 2 * powsum[i - 1] + ((long long) 1 << i); // 2 * powsum[i - 1] + 2 ^ (i-1)
	}
}


long long calcAcc(long long x)
{
	long long result = x % 2;

	for (int i = MAXSIZE; 0 < i; i--) {
		// x가 i 번째 자리가 1 일 때
		if (x & ((long long)1 << i)) {
			result += powsum[i - 1] + (x - ((long long) 1 << i) + 1); // 10..00 인 경우 powsum 추가
			x -= (long long) 1 << i;
		}
	}

	return result;
}

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	long long A, B;

	cin >> A >> B;

	makePowSum();

	cout << calcAcc(B) - calcAcc(A - 1);

}
