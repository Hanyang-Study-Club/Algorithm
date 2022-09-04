#include<iostream>
using namespace std;

int n, m;
int input[1025][1025];
int sum[1025][1025] = { 0 };
int x1, yy1, x2, y2;
int ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for(int j=1;j<=n;j++){
			cin >> input[i][j];
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + input[i][j];
		}
	}

	for(int i=0;i<m;i++){
		cin >> x1 >> yy1 >> x2 >> y2;
		ans = sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][yy1 - 1] + sum[x1 - 1][yy1 - 1];
		cout << ans << "\n";
	}

	return 0;
}