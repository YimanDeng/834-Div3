// Note to self: prefix sum has much cleaner code than 2 pointer
#include <bits/stdc++.h>
using namespace std;

vector<int> v;
vector<int> pref;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int m, n;
    cin >> m >> n;

    // m is the num of clusters, n is num of queries
  
    pref.push_back(0);
    for (int i = 0; i < m; i++) {
        int x; cin >> x;
        v.push_back(x);
        pref.push_back(x + pref[pref.size() - 1]);
    }
  
    set<int> myset (pref.begin(), pref.end());
    
    while (n--) {
        int x; cin >> x;
        bool flag = false;
        if (x <= *pref.rbegin()) {
            int target = *pref.rbegin() - x;
            for (int i = 0; i < pref.size(); i++) {
                if (myset.count(pref[i] - target)) {
                    flag = true;
                    break;
                }
            }
        }
        if (flag) cout << "Yes\n";
        else cout << "No\n";
    }
  
      return 0;
}
