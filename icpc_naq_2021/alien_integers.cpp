#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;

int main() {
    ll n; cin >> n;
    ll m = n;
    set<int> used;
    int most_sig;
    int dig_num = 0;
    while (n != 0) {
        used.insert(n%10);
        dig_num++;
        if (n < 10) most_sig = n;
        n /= 10;
    }
    
    set<int> digits = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

    if (used.size() == 10) cout << "Impossible\n";
    else if (m == 1) cout << 0 << " " << 2;
    else if (m == 1e15) cout << m-1;
    else if (used.size() == 9 && used.count(0) == 0) cout << 0;
    else {
        string res1;
        set<int> can;
        set_difference(digits.begin(), digits.end(), used.begin(), used.end(), inserter(can, can.end()));

        int start_up = most_sig + 1;
        while (true) {
            if (start_up == 10) 
                start_up = 1;
            if (can.count(start_up)) {
                res1 += start_up + '0';
                break;
            }
            start_up++;
        }
        int it1 = start_up < most_sig ? dig_num : dig_num - 1;
        while (it1--) {
            res1 += *can.begin() +'0';
        }

        string res2;
        int start_down = most_sig - 1;
        while (true) {
            if (start_down == 0) 
                start_down = 9;
            if (can.count(start_down)) {
                res2 += start_down + '0';
                break;
            }
            start_down--;
        }
        int it2 = start_down > most_sig ? dig_num - 2 : dig_num - 1;
        while (it2--) {
            res2 += *can.rbegin() +'0';
        }
        

        if (stoll(res1) - m < m - stoll(res2)) cout << res1;
        else if (stoll(res1) - m > m - stoll(res2)) cout << res2;
        else cout << res2 << " " << res1;

    }

    return 0;
}
