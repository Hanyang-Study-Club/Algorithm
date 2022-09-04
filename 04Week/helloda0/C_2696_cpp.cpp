#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int t, n, m;

int main() { 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	cin >> t;
    for (int i = 0; i < t; i++) {
		vector<int> ans;
		priority_queue<int> lpq;
		priority_queue<int, vector<int>, greater<int>> spq;

		cin >> n;
		for (int j = 0; j < n; j++) {
			int num;
			cin >> num;
            if (j == 0){
				m = num;
			} 
			else{
				if (num <= m) {
					lpq.push(num);
				}
				else {
					spq.push(num);
				}
			}
			if(j%2==0){
				if(lpq.size()>spq.size()){
					spq.push(m);
					m = lpq.top();
					lpq.pop();
				}
				else if(lpq.size()<spq.size()){
					lpq.push(m);
					m = spq.top();
					spq.pop();
				}
				ans.push_back(m);
			}
		}
		cout << n / 2 + 1 << "\n";
		for(int j=0;j<ans.size();j++){
			cout << ans[j] << " ";
			if ((j + 1) % 10 == 0) cout << "\n";
		}
		cout << "\n";
	}

    return 0;
}