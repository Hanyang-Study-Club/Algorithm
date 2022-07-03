#include<iostream>
#include<queue>
using namespace std;

int n;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		int item1, item2;
		cin >> item1 >> item2;
		pq.push(make_pair(item1, item2));
	}

	while (pq.empty() != 1) {
		pair<int, int> front = pq.top();
		cout << front.first << " " << front.second << "\n";
		pq.pop();
	}

	return 0;
}
