#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n;
vector<int> p; // vector of astronaut powers
long long h; // humanoid power might overlow later

int solve(int i, long long h, int s2, int s3) {
    if (i == n) return 0; // ran out of astronauts
    if (p[i] < h) { 
        return solve(i+1, h + p[i]/2, s2, s3) + 1; // can absorb
    }
    // here you can choose 2 different serums, choose the max of the two
    int ans1 = (s2 ? solve(i, h * 2, s2 - 1, s3) : 0);
    int ans2 = (s3 ? solve(i, h * 3, s2, s3 - 1) : 0);
    return max(ans1, ans2);
}

int main() {
    int t; cin >> t;
    while (t--) {
        cin >> n >> h; // num of astronauts, humanoid initial power
        p.clear();
        for (int j=0; j<n; j++) {
            int x; cin >> x;
            p.push_back(x);
        }
        sort(p.begin(), p.end()); // sorted power
        cout << solve(0, h, 2, 1) << endl;
    }
    return 0;
}