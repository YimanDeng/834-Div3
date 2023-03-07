/*
example from codeforces

input: rectangle of width w and length h. n of them
output: minimum side length of square such that the all rectangles fit
*/
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

ll w, h, n;

/* 
calculate how many rectangles can a square of side length m fit
compare that number with the number needed
*/
bool isGood(ll m) {
    return (m/w) * (m/h) >= n;
}

int main() {
    cin >> w >> h >> n;

    ll l = 0, r = 1;
    while (!isGood(r)) r *= 2;

    while (l+1<r) {
        ll m = (l+r)/2;
        if (isGood(m)) r = m;
        else l = m;
    }

    cout << r << endl;

    return 0;
}
