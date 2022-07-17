#include<iostream>
#include<set>
using namespace std;

int n, maxsum;
int arr[21] = { 0 };
set<int> s;

void dfs(int now, int sum) {
	s.insert(sum);
	if (now == n) return;
	dfs(now + 1, sum + arr[now]);
	dfs(now + 1, sum);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		maxsum += arr[i];
	}

	dfs(0, 0);
	
	cout << maxsum + 1 - s.size();

	return 0;
}