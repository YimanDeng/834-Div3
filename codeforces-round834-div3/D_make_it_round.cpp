// The key is to realize trailing zeros result from factor of 10, 
// so we want in the factorization of the final number to have as much
// paris of 2 * 5 as possible

#include <bits/stdc++.h>
using namespace std;


int main() {
  int t; cin >> t;
  while (t--) {
    int n, m; cin >> n >> m;
    int original_n = n;
    
    int cnt2 = 0, cnt5 = 0, k = 1;
    
    while (n > 0 && n%2 == 0) {
      n /= 2;
      cnt2++;
    }
    while (n > 0 && n%5 == 0) {
      n /= 5;
      cnt2++;
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
    // add missing part
    if (k == 1) cout << original_n * m << endl;
    else cout << original_n * k << endl;
  }

  return 0;
}
