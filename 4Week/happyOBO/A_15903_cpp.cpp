#include <bits/stdc++.h>

using namespace std;

void solution(int N, int M);

int main() {

	int N, M;
	cin >> N >> M;
	solution(N, M);

	return 0;
}


void solution(int N, int M)
{
	// 최대 1,000,000가 올 수 있는 초기 숫자 1000개 (N)를 최대 15000번 (M) 덮어서 더할 수 있으므로,
	// 최소 숫자 씩 더하는데 N / 2 번 소요 --> 최소 숫자는 X 2 값으로 증가
	// 500 * 30 번 이므로, 최대 합 : 1,000,000 * 2^30 * 1000 => 약 10^12 까지 올 수 있다.

	priority_queue<long long,vector<long long>, greater<long long>> pq;

	long long num;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		pq.push(num);
	}

	long long num1, num2, sum;
	for (int i = 0; i < M; i++)
	{
		num1 = pq.top(); pq.pop();
		num2 = pq.top(); pq.pop();

		sum = num1 + num2;
		pq.emplace(sum);
		pq.emplace(sum);
	}

	long long result = 0;

	while (!pq.empty())
	{
		result += pq.top();
		pq.pop();
	}

	cout << result;
}