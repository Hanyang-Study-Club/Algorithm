#include <bits/stdc++.h>

using namespace std;

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, K;
	int ptr1 , result, acc = 0;

	cin >> N >> K;

	vector<int> v(N);


	for (int i = 0; i < N; i++) cin >> v[i];

	for (int i = 0; i < K; i++) acc += v[i];

	ptr1 = 0;
	result = acc;
	for (int ptr2 = K; ptr2 < N; ptr2++)
	{
		acc -= v[ptr1];
		acc += v[ptr2];
		result = max(result, acc);
		ptr1++;
	}

	cout << result;

}
