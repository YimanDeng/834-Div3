/*
Given n integers, a[l...r] good if the sum on this segment is at least s

Find number of good segments (can also find the min len of such good seg)
*/
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
    ll n, s; cin >> n >> s;
    vector <ll> a(n);
    for (ll i = 0; i < n; i++) cin >> a[i];

    ll cursum = 0, l = 0, res = 0;
    for (ll r = 0; r < n; r++) {
        cursum += a[r];
        while (cursum - a[l] >= s) cursum -= a[l++];
        // while still good, improve
        if (cursum >= s) res += l + 1;  // if want res to be the shortest length, res = min(res, i-l+1)
    }

// num segements with small sum
//       for (int r=0; r<n; r++) {
//         cursum += a[r];
//         while(cursum > s) cursum -= a[l++];
//         count += r - l + 1;
//     }

    cout << res << endl;

    return 0;
}
