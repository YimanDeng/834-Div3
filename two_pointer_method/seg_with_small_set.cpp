/*
Array of n integers, a[l...r] good if no more than k unique
elements on the segment

Find number of good segments
*/
#include <iostream>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;

int main() {

    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];
    map<int, int> m;
    
    int l = 0, count = 0;
    ll res = 0;

    for (int i=0; i<n; i++) {
        m[a[i]]++; 
        if (m[a[i]] == 1) count++;

        while (count > k) {
            m[a[l]]--;
            if (m[a[l]] == 0) count--;
            l++;
        }

        res += i-l+1;
    }

    cout << res << endl;

    return 0;
}
