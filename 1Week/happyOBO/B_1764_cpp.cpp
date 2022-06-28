#include <bits/stdc++.h>

using namespace std;

void solution();
void mergeSort(int lt, int rt);

typedef string T;

vector<T> arr;
vector<T> tmp;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;

	tmp.resize(N);

	// 듣도 못한 사람 이름 set
	set<string> s; 

	string name;
	for (int i = 0; i < N; i++)
	{
		cin >> name;
		s.insert(name);
	}

	for (int i = 0; i < M; i++)
	{
		cin >> name;
		if (s.find(name) != s.end())
			arr.push_back(name);
	}

	tmp.resize(arr.size());

	solution();
}


void solution()
{
	mergeSort(0, arr.size() - 1);

	cout << arr.size() << "\n";
	for_each(arr.begin(), arr.end(), [](T s) {cout << s << "\n"; });
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

