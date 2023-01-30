#include <bits/stdc++.h>
using namespace std;

int main() {
  string s; cin >> s;
  if (s.find('(') == s.size() - 1 - s.find(')')) cout << "correct\n";
  else cout << "fix\n";
  
  return 0;
}
