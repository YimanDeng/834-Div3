#include <iostream>
#include <cctype>
using namespace std;

int main() {

    int t; cin >> t;
    string yes;
    int num = 20;
    while (num--) yes += "Yes";
    
    while (t--) {
        string str; cin >> str;
        if (yes.find(str) == string::npos) cout << "NO" << endl;
        else cout << "YES" << endl;
    }

    return 0;
}
