#include <bits/stdc++.h>

using namespace std;

class FlowerForPrincess
{
	// 날짜를 비교를 쉽게하기 위해 날짜를 하나의 숫자값으로 나타낼 수 있다.
	int calendar[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	const static int MAX_CALENDER = 365;
	vector<pair<int, int>> flowers;
	int start_time, end_time; // 공주가 원하는 시작 , 끝 시간

	int Calendar2Int(int m, int d)
	{
		int result = 0;
		for (int i = 1; i < m; i++)
		{
			result += calendar[i];
		}
		result += d;

		return result;
	}

	void UpdateTime(int& start_time, int& end_time, pair<int, int>& flower)
	{
		int start_term = 0, end_term = 0;
		// 시작하는 시간을 기준으로 했을 때 기간
		if (flower.first <= start_time)
		{
			start_term = flower.second - start_time;
		}
		// 끝나는 시간을 기준으로 했을 때 기간 
		if (end_time <= flower.second)
		{
			end_term = end_time - flower.first;
		}

		if (start_term < end_term)
		{
			end_time = flower.first -1;
		}
		else
		{
			start_time = flower.second + 1;
		}
	}


public:

	FlowerForPrincess() {}
	FlowerForPrincess(int st_month, int st_day, int end_month, int end_day)
	{
		start_time = Calendar2Int(st_month, st_day);
		end_time = Calendar2Int(end_month, end_day);
	}

	void Input()
	{
		int N;
		cin >> N;

		int st_m, st_day, ed_m, ed_day;
		pair<int, int> flower; // 개화 시간 , 폐화(?) 시간
		for (int i = 0; i < N; i++)
		{
			cin >> st_m >> st_day >> ed_m >> ed_day;
			flower.first = Calendar2Int(st_m, st_day);
			flower.second = Calendar2Int(ed_m, ed_day);

			if (flower.first != flower.second)
			{
				flowers.push_back(flower); 
			}

		}
	}

	int Solve()
	{
		pair<int, int> flower;
		//auto sorter = [&](pair<int, int>& a, pair<int, int>& b)
		//{
		//	int a_term = 0, b_term = 0;
		//	if (a.first <= start_time && a.first <= end_time) a_term = a.second - start_time;

		//	if (b.first <= start_time && b.first <= end_time) b_term = b.second - start_time;

		//	if (end_time <= a.second && a.second <= start_time) a_term = max(a_term, end_time - a.first);

		//	if (end_time <= b.second && b.second <= start_time) b_term = max(b_term, end_time - b.first);


		//	return a_term < b_term;
		//};

		auto sorter = [&](pair<int, int>& a, pair<int, int>& b)
		{
			return a < b;
		};

		sort(flowers.begin(), flowers.end(), sorter);

		int now = start_time, counter = 0, index, max = 0;

		for (int i = 0; i < flowers.size(); i++)
		{
			flower = flowers[i];
			if (end_time < now) break;
			if (max < flower.second && flower.first <= now) // 전에 탐색했던 기간보다 오래 버티고, 현재 탐색 시점을 포함한다면, index 업데이트
			{
				index = i;
				max = flower.second;
			}

			if (flower.first > now && max != 0)
			{
				// 포함하지 않는 기간이 온다면, 현재 탐색 시점을 index 값으로 업데이트 해주고 개수 증가
				now = flowers[index].second;
				counter++;
				i--;
				max = 0;
			}

			else if (max != 0 && i == flowers.size() - 1)
			{
				// 더이상 탐색할 게 없는 경우
				now = flowers[index].second;
				counter++;
			}

			else if (max == 0)
			{
				counter = 0;
				break;
			}
		}

		if (now <= end_time)
			counter = 0;
		
		return counter;


	}

};



int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	FlowerForPrincess FFP = FlowerForPrincess(3, 1, 11, 30);
	FFP.Input();
	cout << FFP.Solve();
}
