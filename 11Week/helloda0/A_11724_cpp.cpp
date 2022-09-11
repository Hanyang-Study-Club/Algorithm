#include<iostream>
#include<vector>
using namespace std;

int n, m;
vector<int> v[1010];
int checked[1010] = { 0 };
int ans = 0;

void dfs(int x){
	checked[x] = 1;
	for(int i=0;i<v[x].size();i++){
		if(!checked[v[x][i]]) dfs(v[x][i]);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//input
	cin >> n >> m;
	for(int i=0;i<m;i++){
		int n1, n2;
		cin >> n1 >> n2;
		v[n1].push_back(n2);
		v[n2].push_back(n1);
	}

	for(int i=1;i<=n;i++){
		if(!checked[i]){
			dfs(i);
			ans++;
		}
	}

	cout << ans;

	return 0;
}