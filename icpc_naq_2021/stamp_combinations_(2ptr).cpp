// Note to self: global variables are 0 by default
// if not declared globally, remember to initialize ints
#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int sum, target;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int m, n;
    cin >> m >> n;

    
    // m is the num of clusters, n is num of queries
    for (int i = 0; i < m; i++) {
        int x; cin >> x;
        v.push_back(x);
        sum += x;
    }

    while (n--) {
        cin >> target;
        target = sum - target;
        
        // two pointer
        int i = 0, j = 0, cur_sum = 0;
        bool cando = false;
        while (i < m) {
            if (target < 0) break;
            if (target == 0 || target == sum) {
                cando = true; 
                break;
            }
            while (j < m && cur_sum < target) {
                cur_sum += v[j]; j++; 
            }
            while (i < m && cur_sum > target) {
                cur_sum -= v[i]; i++;
            }
            if (cur_sum == target) {
                cando = true; 
                break;
            }
            if (j == m && cur_sum < target) break;
        }
        if (cando) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}
