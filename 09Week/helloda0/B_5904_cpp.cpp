#include<iostream>
#define ll long long
using namespace std;

ll n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	ll len = 3;
	ll midlen = 3;

	while(len<n){
		midlen++;
		len = len * 2 + midlen;
	}

	while(1){
		ll t = (len - midlen) / 2;

		if(t >= n){
			midlen--;
			len = t;
		}
		else if(t + midlen < n){
			n -= t + midlen;
			midlen--;
			len = t;
		}
		else{
			n -= t;
			break;
		}
	}

	if (n == 1) cout << "m";
	else cout << "o";

	return 0;
}