#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int n, m;
vector<string> names, dbjs;
int cnt=0;

void Pre() {
	cin >> n >> m;
	for (int i = 0; i < n+m; i++) {
		string name;
		cin >> name;
		names.push_back(name);
	}
	sort(names.begin(), names.end());
	for (int i = 0; i < n+m-1; i++) {
		if (names[i] == names[i+1]) {
			cnt++;
			dbjs.push_back(names[i]);
		}
	}
}

//void Sort() {
//	// sort 구현,,,
//	
//}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	Pre();
	//Sort();

	cout << cnt << "\n";
	for (int i = 0; i < cnt; i++) {
		cout << dbjs[i] << "\n";
	}

	return 0;
}
