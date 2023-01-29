/*
The point is that the product of any 2 numbers in the input array is unique
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

    vector<int> v = {4, 8, 15, 16, 23, 42};
    int ans[4];
    for (int i=0; i<4; i++) {
        printf("? %d %d\n", i+1, i+2);
        cout.flush();
        cin >> ans[i];
    }
    while (next_permutation(v.begin(), v.end())) {
        bool good = true;
        for (int i=0; i<4; i++) {
            if (ans[i] != v[i] * v[i+1]) {
                good = false;
            }
        }
        if (good) break;
    }
    cout << "!";
    for (auto elem : v) 
        printf(" %d", elem);
    cout << endl;
    return 0;
}
