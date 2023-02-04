#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int t; cin >> t;
    while(t--) {
        string sub; cin >> sub;
        string c = "codeforces";
        if (c.find(sub) != string::npos) cout << "YES\n";
        else cout << "NO\n";
    }
 
    return 0;
}
