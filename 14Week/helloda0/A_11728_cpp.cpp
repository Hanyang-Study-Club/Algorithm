#include<iostream>
using namespace std;

int n, m;
int arr1[1000010];
int arr2[1000010];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> arr1[i];
	}
	for(int i=0;i<m;i++){
		cin >> arr2[i];
	}
	int p1 = 0, p2 = 0;
	while(1){
		if(p1==n){
			while(p2!=m){
				cout << arr2[p2++]<<" ";
			}
			break;
		}
		else if (p2 == m) {
			while (p1 != n) {
				cout << arr1[p1++]<<" ";
			}
			break;
		}
		else if(arr1[p1]<arr2[p2]) cout << arr1[p1++]<<" ";
		else if(arr1[p1]>arr2[p2]) cout << arr2[p2++]<<" ";
		else{
			cout << arr1[p1++] << " " << arr2[p2++] << " ";
		}
	}



	return 0;
}