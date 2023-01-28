#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int l; cin >> l;
        string s; cin >> s;
        if ((s.find("8") != -1) && (s.size() - s.find("8") >= 11)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}
