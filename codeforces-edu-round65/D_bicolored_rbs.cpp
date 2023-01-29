#include<bits/stdc++.h>
using namespace std;

int len;
string s;
string res;

int main() {
    cin >> len;
    cin >> s;
    int cc = 0;
    char prev = 'a';

    string res;
    for (int i=0; i<len; i++) {
        char cur = s[i];
        if (cur == prev) {
            cc ^= 1;
        }
        res += (cc == 0) ? '0' : '1';
        prev = cur;
    }
    cout << res << endl;
    return 0;
}

