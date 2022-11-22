#include <iostream>
#include <vector>
#include <set>
using namespace std;

bool isGood(int m, int s) {
    if (s < 0) return false;
    if (s == 0) return true;
    else return isGood(m+1, s-(m+1));
}

int main() {
    int t; cin >> t;
    while (t--) {
        int m; cin >> m; // num of found
        int s; cin >> s; // sum of lost
        set<int> a;
        int maxE = -1;
        for (int i=0; i<m; i++) {
            int x; cin >> x; 
            maxE = max(maxE, x);
            a.insert(x);
        }
        for (int i=1; i<=maxE; i++) { // loop 1 through max of found elements
            if (a.find(i) == a.end()) s -= i; // not in found
        }
        
        if (isGood(maxE, s)) cout << "YES" << endl;
        else cout << "NO" << endl;

    }
    return 0;
}