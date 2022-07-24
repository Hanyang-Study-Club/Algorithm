//#include <iostream>
//#include <queue>
//#define ll long long
//using namespace std;
//
//int n, m;
//ll ans;
//priority_queue<ll, vector<ll>, greater<ll>> pq;
//
//int main() {
//  ios_base::sync_with_stdio(false);
//  cin.tie(0);
//  cout.tie(0);
//
//  cin >> n >> m;
//  for (int i = 0; i < n; i++) {
//    ll inp;
//    cin >> inp;
//    pq.push(inp);
//  }
//
//  for (int i = 0; i < m; i++) {
//    ll fir = pq.top();
//    pq.pop();
//    ll sec = pq.top();
//    pq.pop();
//    pq.push(fir + sec);
//    pq.push(fir + sec);
//  }
//
//  for (int i = 0; i < n; i++) {
//    ans += pq.top();
//    pq.pop();
//  }
//  cout << ans;
//
//  return 0;
//}