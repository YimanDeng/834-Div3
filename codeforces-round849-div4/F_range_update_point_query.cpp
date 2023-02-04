/*
Note to self: I had to read the tutorial for this one
Key is that single digit numbers don't change under query 1
All numbers from 1:1e9 will be single digit after 3 iter ot query 1
e.g., max sum of digit f(999,999,999) = 81; 
from 1 to 81, max sum of digit f(79) = 16;
from 1 to 16, max sum of digit f(9) = 9;
Another key is to use a set to store the active indices
*/
#include <bits/stdc++.h>
using namespace std;
//typedef long long ll;
//typedef pair<long, long> pll;

int sum_dig(int num) {
    int res = 0;
    while (num) {
        res += num%10;
        num /= 10;
    }
    return res;
}

void solve() {
    int n, q; cin >> n >> q; //array len n, num of queries q
    vector<int> v(n);
    set<int> s; // indices of numbers that are NOT stable
    for (int i=0; i <n; i++) { // need for loop because need i
        cin >> v[i];
        if (v[i] > 9) s.insert(i);
    }
    while (q--) {
        int type; cin >> type;
        if (type == 1) {
            int l, r; cin >> l >> r;
            l--, r--;
            // find the array from l to r
            while (!s.empty()) {
                auto it = s.lower_bound(l);
                if (it == s.end() || *it > r) break; // no index between l and r
                int ind = *it;
                v[ind] = sum_dig(v[ind]); 
                s.erase(it);
                if (v[ind] > 9) s.insert(ind);
                l = ind + 1;
            }
        } else {
            int x; cin >> x; x--;
            cout << v[x] << endl;
        }
    }

}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--) {
        solve();
    }
}
