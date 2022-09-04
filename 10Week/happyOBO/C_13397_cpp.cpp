#include <bits/stdc++.h>
#include <climits>

using namespace std;

// 이분 탐색 기준 : 최대값의 최소값을 k 할 수 있는지
// - 할 수 있다 : 최소값을 감소 후 재 탐색
// - 할 수 없다 : 최소값을 증가 후 재 탐색
bool CanGetMinValue(vector<int>& v, int term_max_count, int target_min_score);

int BinarySearch(vector<int>& v, int term_max_count)
{
	int start = 0;
	int end = *max_element(v.begin(), v.end()); // 자연수만 올 수 있으므로, 원소 최대값이 제일 큰 차이값
	int mid;
	int curr_min_score = INT_MAX;

	while (start <= end)
	{
		mid = (start + end) / 2;

		if (CanGetMinValue(v, term_max_count, mid))
		{
			curr_min_score = min( curr_min_score,  mid);
			end = mid - 1;
		}
		else
		{
			start = mid + 1;
		}
	}

	return curr_min_score;

}

bool CanGetMinValue(vector<int>& v, int term_max_count, int target_min_score)
{
	// 구간 점수가 target_min_value 를 넘기면
	// 구간을 분할 시도
	// 구간 개수가 term_max_count 을 넘지 않으면 true, 아니면 false 리턴

	int term_count = 1;
	int curr_min_value = INT_MAX, curr_max_value = INT_MIN;

	for (auto num : v)
	{
		if (num < curr_min_value)
		{
			if (curr_max_value != INT_MIN && target_min_score < curr_max_value - num)
			{
				// 구간 분할 및 초기화
				term_count++;
				curr_max_value = curr_min_value = num;
			}
			else curr_min_value = num;
		}
		if (curr_max_value < num)
		{
			if (curr_min_value != INT_MAX && target_min_score < num - curr_min_value)
			{
				// 구간 분할 및 초기화
				term_count++;
				curr_max_value = curr_min_value = num;
			}
			else curr_max_value = num;
		}
	}

	return term_count <= term_max_count;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, m_term;
	cin >> N >> m_term;

	vector<int> v(N);

	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}

	cout << BinarySearch(v, m_term);

	return 0;
}

