#include<iostream>
#include<algorithm>
using namespace std;

int n, k;
int arr[100010];
int arrsum[100010];
int ans = 0;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> k;
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	for (int j = 0; j < k; j++) {
		arrsum[0] += arr[j];
	}
	for(int i=1;i<n-k+1;i++){
		arrsum[i] = arrsum[i-1] - arr[i-1] + arr[i + k-1];
	}
	cout << *max_element(arrsum, arrsum + n - k + 1);

	return 0;
}