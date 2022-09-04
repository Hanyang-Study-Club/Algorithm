#include<iostream>
#include<map>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

bool cmp(pair<string, int> left, pair<string, int> right) {
	if (left.second != right.second) {
		return left.second > right.second;
	}
	else {
		if (left.first.length() != right.first.length()) {
			return left.first.length() > right.first.length();
		}
		return left.first < right.first;
	}
}

int n, m;
map<string, int, greater<string>> dict;
map<string, int>::iterator p;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (s.length() < m) continue;
		p = dict.find(s);
		if (p != dict.end()) dict[s]++;
		else dict[s] = 1;
	}

	vector<pair<string, int>> v(dict.begin(), dict.end());
	sort(v.begin(), v.end(), cmp);
	
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << "\n";
	}


	return 0;
}