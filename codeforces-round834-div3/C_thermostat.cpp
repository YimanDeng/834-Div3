// The key is to think about the different cases
// also realize: for a number i, the farthest another number j can be from i is when j is at l/r
// So, either a=b, or a->b, or a -> l/r -> b, or to a -> l/r -> r/l -> b
// if not reachable form both boarders, then b not reachable
#include <bits/stdc++.h>
using namespace std;

int num(int l, int r, int x, int a, int b) {
  if (a == b) return 0;
  if (abs(a-b) >= x) return 1;
  if (r - max(a, b) >= x || min(a, b) - l >= x) return 2;
  if ((r - b >= x && a - l >= x) || (b - l >= x && r - a >= x)) return 3 ;
  return -1;
}

int main() {
  int t; cin >> t;
  while (t--) {
    int l, r, x, a, b;
    cin >> l >> r >> x >> a >> b;
    cout << num(l, r, x, a, b) << endl;
  }
  
  return 0;
}
