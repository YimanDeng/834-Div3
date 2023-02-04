#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string s; cin >> s;
        int l = 0, r = n-1;
        int len = 0;
        while (r >= l) { 
            if ((s[l] == '1' && s[r] == '0') || (s[r] == '1' && s[l] == '0')) { 
                if (r != l) {
                    len += 2; 
                }
                r--; l++; 
            }
            else break;
        }

        len = n - len;
        cout << len << endl;
    }

    return 0;
}
