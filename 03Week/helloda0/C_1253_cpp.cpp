#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;

int n;
ll arr[2001] = { 0 };
int ans = 0;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);

	for (int i = 0; i < n; i++) {
		ll now = arr[i];
		int l = 0, r = n - 1;
		while (l < r) {
			if (arr[l] + arr[r] == now) {
				if (l != i && r != i) {
					ans++;
					break;
				}
				else if (l == i) l++;
				else if (r == i) r--;
			}
			else if (arr[l] + arr[r] < now) l++;
			else r--;
		}
	}
	cout << ans;

	return 0;
}