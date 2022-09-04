#include<iostream>
#include<algorithm>
using namespace std;

int n;
int arr[1030][1030];
int secpick[4] = { 10000, 10000, 10000, 10000 };

void sol(int num){

	for(int j=0;j<num/2;j++){
		for(int i=0;i<num/2;i++){
			secpick[0] = arr[i * 2][j * 2];
			secpick[1] = arr[i * 2 + 1][j * 2];
			secpick[2] = arr[i * 2][j * 2 + 1];
			secpick[3] = arr[i * 2 + 1][j * 2 + 1];
			sort(secpick, secpick + 4);
			arr[i][j] = secpick[2];
		}
	}
	if (num == 2) {
		return;
	}
	sol(num / 2);
	return;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin >> arr[i][j];
		}
	}

	sol(n);
	cout << arr[0][0];

	return 0;
}