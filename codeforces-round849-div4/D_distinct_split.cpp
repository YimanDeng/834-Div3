// Note to self: key is to use 2 frequency arrays
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<long, long> pll;

// using two frequency arrays to keep dynamic count of num fo distinct chars in a and b
void solve() {
    int n; cin >> n;
    string s; cin >> s;
    vector<int> freq(26, 0), pref(26, 0);
    for (auto e : s) {
        freq[e-'a']++;
    }
    int max_num = 0;
    for (auto e : s) { // loop through string to find best breaking point
        freq[e-'a']--;
        pref[e-'a']++;
        int cur_num = 0;
        for (int i=0; i<26; i++) { // count f(a) + f(b)
            cur_num += min(1, freq[i]) + min(1, pref[i]);
        }
        max_num = max(cur_num, max_num);
    }
    cout << max_num << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
}
