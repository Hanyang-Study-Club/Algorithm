#include<iostream>
#include<string>
using namespace std;

string s;
int num = 0;
int ans = 0;
bool flag = 1;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> s;

	for(int i=0;i<s.size();i++){
		if (s[i] == '+' || s[i] == '-') {
			if (flag) {
				ans += num;
				num = 0;
			}
			else {
				ans -= num;
				num = 0;
			}
		}
		else{
			num = num * 10 + (s[i] - '0');
		}
		if (s[i] == '-') flag = 0;
	}

	if (flag) ans += num;
	else ans -= num;

	cout << ans;

	return 0;
}