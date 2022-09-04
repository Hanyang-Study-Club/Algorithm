#include <bits/stdc++.h>
#include <climits>

using namespace std;

// 가운데 까만 곳에 위치하면 1 을 리턴
// 아니라면 그보다 작은 프랙탈로 탐색
int GetColor(int s, int N, int K, int r, int c)
{
	int curr_size = s; // 현재 탐색하는 시간 크기
	int curr_N_size, curr_K_size; // 현재 프랙탈 사이즈, 가운데 까만 곳 크기
	int mid_k_min, mid_k_max; // 가운데 까만 곳 범위
	int curr_r = r , curr_c = c;

	while (0 < curr_size)
	{
		curr_N_size = pow(N, curr_size);
		curr_K_size = K * pow(N, curr_size - 1);

		mid_k_min = curr_N_size / 2 - curr_K_size / 2;
		mid_k_max = curr_N_size / 2 + curr_K_size / 2;

		if (curr_K_size % 2 == 1) mid_k_max++;

		curr_r %= curr_N_size;
		curr_c %= curr_N_size;

		if (mid_k_min <= curr_r && curr_r < mid_k_max &&
			mid_k_min <= curr_c && curr_c < mid_k_max)
		{
			return 1;
		}

		curr_size--;
	}
	return 0;
}


int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int s, N, K, R1, R2, C1, C2;
	cin >> s >> N >> K >> R1 >> R2 >> C1 >> C2;

	for (int r = R1; r <= R2; r++)
	{
		for (int c = C1; c <= C2; c++)
		{
			cout << GetColor(s, N, K, r, c);
		}
		cout << "\n";
	}
}

