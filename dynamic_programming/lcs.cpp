#include <iostream>
#include <string>
//#include 
using namespace std;


int lcs(string s1, string s2) {
    int d[s1.size() + 1][s2.size() + 1];
    for (int i = 0; i <= s1.size(); i++) {
        d[i][0] = 0;
    }
    for (int i = 0; i <= s2.size(); i++) {
        d[0][i] = 0;
    }
    for (int m = 1; m <= s1.size(); m++) {
        for (int n = 1; n <= s2.size(); n++) {
            d[m][n] = s1[m] == s2[n] ? d[m-1][n-1] + 1 : max(d[m-1][n], d[m][n-1]);
        }
    }
    return d[s1.size()][s2.size()];
}

int main() {
    string s1; cin >> s1;
    string s2; cin >> s2;

    // print the length of the longest commen subsequence of two strings
    cout << "length of LCS of " << s1 << " and " << s2 << " is " << lcs(s1, s2) << endl;

    // print the length of the longest palindrome
    string s1_temp = s1;
    reverse(s1.begin(), s1.end());
    cout << "length of longest palindrome of " << s1_temp << " is " << lcs(s1_temp, s1) << endl;

    return 0;
}

