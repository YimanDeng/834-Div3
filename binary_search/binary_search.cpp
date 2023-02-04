/*
input: n - length of array, k - number of queries
followed by n elements of the array and k queries

output: YES or NO indicating query in array or not
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];

    for (int i=0; i<k; i++) {
        int q; cin >> q;
        int l = 0, r = n-1;
        bool ok = false;
        while (l<=r) {
            int m = (l+r) / 2;
            if (q == a[m]) {
                ok = true;
                break;
            }
            else if (q < a[m]) r = m-1;
            else l = m+1;
        }
        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}

/* 
Closest to the left/right
This is the implementation for closest to l
Idea: maintain invariant l <= q and r > q;
*/
int main() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];

    for (int i=0; i<k; i++) {
        int q; cin >> q;
        int l = -1, r = n;
        bool ok = false;
        while (l+1<r) {
            int m = (l+r) / 2;
            if (q < a[m]) r = m; // <= for r
            else if (q >= a[m]) l = m; // > for r
        }
        // a better way to implement binary search, just add check if l == q
        cout << l << endl; // beware if problem statement uses 1-indexing
    }

    return 0;
}
