#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve() {
  int n, m; cin >> n >> m;
  vector<ll> a;
  ll j = 0;
  while (n--) {
      ll x; cin >> x;
      a.push_back(x+j);
      j++;
  }
  sort(a.begin(), a.end());
  int i = 0;
  while (i < a.size() && m-1 >= a[i]) {
      m--;
      m -= a[i]; //cout << a[i] << endl;
      i++;
  }
  cout << i << endl;
}
 
int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
}
