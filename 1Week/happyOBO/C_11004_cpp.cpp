#include <bits/stdc++.h>

using namespace std;

void solution(int K);
void mergeSort(int lt, int rt);

typedef int T;

vector<T> arr;
vector<T> tmp;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, K;
	cin >> N >> K;

	arr.resize(N);
	tmp.resize(N);

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}


	solution(K);
}


void solution(int K)
{
	mergeSort(0, arr.size() - 1);

	cout << arr[K - 1];
}


void mergeSort(int lt, int rt)
{
	int mid;
	int p1, p2, p3;
	if (lt < rt)
	{
		mid = (lt + rt) / 2;
		mergeSort(lt, mid);
		mergeSort(mid + 1, rt);

		p1 = lt; p2 = mid + 1; p3 = lt;

		while (p1 <= mid && p2 <= rt)
		{
			if (arr[p1] < arr[p2]) tmp[p3++] = arr[p1++];
			else tmp[p3++] = arr[p2++];
		}

		while (p1 <= mid) tmp[p3++] = arr[p1++];
		while (p2 <= rt) tmp[p3++] = arr[p2++];

		for (int i = lt; i <= rt; i++) arr[i] = tmp[i];

	}

}

