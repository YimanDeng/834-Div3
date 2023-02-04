#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int x = 0, y = 0;
        bool b = false;
        string d; cin >> d;
        for (int i=0; i < d.size(); i++) {
            char c = d[i];
            if (c == 'U') y++;
            else if (c == 'D') y--;
            else if (c == 'L') x--;
            else if (c == 'R') x++;
            if (x == 1 && y == 1) {
                b = true;
                break;
            }
        }
        
        if (b) cout << "yes\n";
        else cout << "no\n";
 
    }
 
    return 0;
}
