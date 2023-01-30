#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  int cur; int prev;
  cin >> prev;

  int i = 0;
  while (i < n-1) {
    cin >> cur; i++;
    if (cur % prev == 0) {
        cout << cur << endl;;
        cin >> prev; i++;
    }
  }

  return 0;
}
