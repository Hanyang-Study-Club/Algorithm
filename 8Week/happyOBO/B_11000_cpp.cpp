#include <bits/stdc++.h>

using namespace std;

// 시작 시간이 이른 것부터 채워서,
// 현재 추가된 방들 중에서 끼워넣을 수 있으면 업데이트 하고
// 방들은 끝나는 시간이 이른 시간부터 차례대로 탐색
// 아니면 방을 추가한다.

void input(priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>& lessons)
{
	int N;
	cin >> N;

	pair<int, int> lesson;
	for (int i = 0; i < N; i++)
	{
		cin >> lesson.first >> lesson.second;
		lessons.emplace(lesson);
	}
}

void solve(priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>& lessons
	, priority_queue<int, vector<int>, greater<int>>& rooms)
{
	int end_time;
	pair<int, int> lesson;
	while (!lessons.empty())
	{
		lesson = lessons.top(); lessons.pop();

		if (rooms.empty()) rooms.emplace(lesson.second);
		else
		{
			end_time = rooms.top();
			if (end_time <= lesson.first) rooms.pop();
			// top 값인 강의실 값 업데이트 or 강의실 하나 추가
			rooms.emplace(lesson.second);
		}
	}

}

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> lessons;
	// 해당 강의실의 마지막 수업의 끝나는 시간을 담고 있음
	// top : 현재 강의실들 중 가장 끝나는 시간이 이른 값
	priority_queue<int, vector<int>, greater<int>> rooms; 
	
	input(lessons);

	solve(lessons, rooms);

	cout << rooms.size();

}
