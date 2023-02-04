/*
array a size n array b size m sorted. find number of pairs
(i, j) for which a[i] == b[j]
*/

#include <iostream>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main() {

    int n, m; cin >> n >> m;
    vector<ll> a(n), b(m);
    for (int i=0; i<n; i++) cin >> a[i];
    for (int j=0; j<m; j++) cin >> b[j];

    ll i = 0, j = 0, total = 0;
    while (i < n) {
        int count = 0;
        while (j < m && b[j] <= a[i]) {
            if (b[j++] == a[i]) count++;
        }
        total += count;
        while (i < n-1 && a[i] == a[i+1]) {
            i++;
            total += count;
        }
        i++;
    }

    cout << total << endl;

    return 0;
}
