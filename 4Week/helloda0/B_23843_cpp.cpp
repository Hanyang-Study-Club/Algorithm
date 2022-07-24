//#include<iostream>
//#include<queue>
//#define ll long long
//using namespace std;
//
//int n, m;
//ll ans;
//priority_queue<ll> pq;
//priority_queue<ll, vector<ll>, greater<ll>> pq2;
//
//int main() {
//  ios_base::sync_with_stdio(false);
//  cin.tie(0);
//  cout.tie(0);
//
//  cin >> n >> m;
//  for (int i = 0; i < n; i++){
//    int num;
//    cin >> num;
//    pq.push(num);
//  }
//
//  if (m == 1) {
//    for (int i = 0; i < n; i++) {
//      ans += pq.top();
//      pq.pop();
//	}
//    cout << ans;
//    return 0;
//  }
//
//  else if (n < m) {
//    cout << pq.top();
//    return 0;
//  }
//  
//  for (int i = 0; i < m; i++) {
//    pq2.push(pq.top());
//    pq.pop();
//  }
//  for (int i = m; i < n; i++) {
//    ll num = pq2.top() + pq.top();
//    pq2.pop();
//    pq.pop();
//    pq2.push(num);
//  }
//
//  while (pq2.size()!=1) {
//    pq2.pop();
//  }
//  cout << pq2.top();
//
//  return 0;
//}