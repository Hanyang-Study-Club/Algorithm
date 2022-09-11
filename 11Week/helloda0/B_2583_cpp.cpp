#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

struct yx{
	int y, x;
};

int m, n, k;
int ans = 0;
int rect[110][110] = { 0 };
queue<yx> q;
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };
int nsize;
vector<int> v;

void bfs(int r, int c){
	while(!q.empty()){
		yx now = q.front();
		for(int i=0;i<4;i++){
			int y = now.y + dr[i];
			int x = now.x + dc[i];
			if (y < 0 || y >= n || x < 0 || x >= m || rect[y][x]) continue;
			nsize++;
			rect[y][x] = 1;
			yx nnyx = { y,x };
			q.push(nnyx);
		}
		q.pop();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//input
	cin >> m >> n >> k;
	for(int i=0;i<k;i++){
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for(int j=x1;j<x2;j++){
			for(int k=y1;k<y2;k++){
				rect[j][k] = 1;
			}
		}
	}

	for(int i=0;i<n;i++){
		for (int j = 0;j<m;j++){
			if(!rect[i][j]){
				nsize = 1;
				yx narea = { i,j };
				q.push(narea);
				rect[i][j] = 1;
				bfs(i, j);
				ans++;
				v.push_back(nsize);
			}
		}
	}

	sort(v.begin(), v.end());

	cout << ans << "\n";
	for(int i=0;i<v.size();i++){
		cout << v[i] << " ";
	}

	return 0;
}