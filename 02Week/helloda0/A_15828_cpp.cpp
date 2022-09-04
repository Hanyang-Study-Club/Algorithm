#include<iostream>
#include<queue>
using namespace std;

int n;
queue<int> q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	while(1) {
		int newp;
		cin >> newp;
		if (newp > 0 && q.size()<n) {
			q.push(newp);
		}
		else if (newp == 0) {
			q.pop();
		}
		else if(newp == -1) {
			break;
		}
	}
	if (q.empty()) {
		cout << "empty";
		return 0;
	}

	while (!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}
	return 0;
}
