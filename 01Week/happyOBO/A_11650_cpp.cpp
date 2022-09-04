#include <bits/stdc++.h>

using namespace std;

template <class T>
class MergeSorter
{
public:
	MergeSorter() {}
	MergeSorter(int N) 
	{
		arr.resize(N);
		tmp.resize(N);
	}
	vector<T> Sort()
	{
		MergeSort(0, arr.size() - 1);

		return arr;
	}

public:
	vector<T> arr;

private:
	vector<T> tmp;
	void MergeSort(int lt, int rt)
	{
		int mid;
		int p1, p2, p3;
		if (lt < rt)
		{
			mid = (lt + rt) / 2;
			MergeSort(lt, mid);
			MergeSort(mid + 1, rt);

			p1 = lt; p2 = mid + 1; p3 = lt;

			while (p1 <= mid && p2 <= rt)
			{
				if (arr[p1] < arr[p2])tmp[p3++] = arr[p1++];
				else tmp[p3++] = arr[p2++];
			}

			while (p1 <= mid) tmp[p3++] = arr[p1++];
			while (p2 <= rt) tmp[p3++] = arr[p2++];

			for (int i = lt; i <= rt; i++) arr[i] = tmp[i];

		}

	}

};


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	MergeSorter<pair<int, int>> sorter = MergeSorter<pair<int, int>>(N);

	for (int i = 0; i < N; i++)
	{
		cin >> sorter.arr[i].first >> sorter.arr[i].second;
	}

	vector<pair<int,int>> result = sorter.Sort();

	for_each(result.begin(), result.end(), 
		[](pair<int, int> p) 
		{ 
			cout << p.first << " " << p.second << "\n";
		});
}

