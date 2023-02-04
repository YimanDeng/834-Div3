// Note to self: remember to use ll when summing multiple 1e9 integers
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> pos;
        vector <int> neg;
        while (n--) {
          int x; cin >> x;
          if (x>=0) pos.push_back(x);
          if (x<0) neg.push_back(x);
        }
        sort(pos.begin(), pos.end());
        sort(neg.begin(), neg.end());
        int i = 0, j = 0;
        while (neg.size() - i >= 2 && i < neg.size()-1) {
          pos.push_back(-neg[i]); i++;
          pos.push_back(-neg[i]); i++;
        }
        while (i < neg.size() && neg.size()>0 && pos.size()>0 && abs(neg[i]) > pos[j]) {
          if (neg[i] >= 0) break;
          neg.push_back(-pos[j]);
          pos.push_back(-neg[i]);
          i++;
          j++;
        }
        ll sum = 0;
        for (int e = j; e < pos.size(); e++) {
          sum += pos[e]; 
        }
        for (int e = i; e < neg.size(); e++) {
          sum += neg[e];
        }
        cout << sum << endl; 
    }
 
    return 0;
}
