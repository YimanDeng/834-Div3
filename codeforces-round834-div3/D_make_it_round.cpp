// The key is to realize trailing zeros result from factor of 10, 
// so we want in the factorization of the final number to have as much
// paris of 2 * 5 as possible
// Note to self: n, m are of O(1e9), when multiplied with others might overflow, so use ll

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  int t; cin >> t;
  while (t--) {
    ll n, m; cin >> n >> m;
    ll original_n = n;
    
    ll cnt2 = 0, cnt5 = 0, k = 1;
    
    while (n > 0 && n%2 == 0) {
      n /= 2;
      cnt2++;
    }
    while (n > 0 && n%5 == 0) {
      n /= 5;
      cnt5++;
    }
    while (cnt2 < cnt5 && 2*k <= m) {
      cnt2++;
      k *= 2;
    }
    while (cnt5 < cnt2 && 5*k <= m) {
      cnt5++;
      k *= 5;
    }
    while (10*k <= m) {
      k *= 10;
    }
    // note that now we can't have more trailing 0s, but we must find the largest such number
    // so, multiples of itself, the total number of multiples is m / k
    // original_n should be multiplied with m / k
    if (k == 1) cout << original_n * m << endl;
    else {
        k = m / k * k;
        cout << original_n * k << endl;
    }
  }

  return 0;
}
