#include<iostream>
using namespace std;

int n, k;
int input[101];
int sum[101] = { 0 };
int ans = -99999;
int temp = 0;

void Input(){
	cin >> n >> k;
	input[0] = 0;
	for(int i = 1; i <= n; i++){
		cin >> input[i];
		temp += input[i];
		sum[i] += temp;
	}
}

void Solve(){
	for(int i = k; i <= n; i++){
		if (sum[i] - sum[i - k] > ans) ans = sum[i] - sum[i - k];
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	Input();
	Solve();

	cout << ans;

	return 0;
}