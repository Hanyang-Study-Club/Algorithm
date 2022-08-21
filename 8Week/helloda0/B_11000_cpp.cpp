#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int n;
vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<int>> pq;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for(int i=0;i<n;i++){
		pair<int, int> newpair;
		cin >> newpair.first >> newpair.second;
		v.push_back(newpair);
	}
	sort(v.begin(), v.end());

	pq.push(v[0].second);
	for(int i=1;i<n;i++){
		if(pq.top()<=v[i].first){
			pq.pop();
			pq.push(v[i].second);
		}
		else{
			pq.push(v[i].second);
		}
	}
	cout << pq.size();

	return 0;
}