#include <bits/stdc++.h>
using namespace std;

int n, p;

bool check(vector<int> &a, int x) {
    bool cr = (a[n-1] + x >= p);
    int d = (a[n-1] + x) % p, rem = p - x - 1;
    auto need = [&](int y) {
        return cr ? (y > d && y < a[n-1]) : (y > d || y < a[n-1]);
    };
    unordered_set<int> seen;
    auto add = [&](int y) {
        if(!seen.count(y) && need(y))
            rem--;
        seen.insert(y);
    };
    if(cr) {
        int pos = n-1;
        while(pos > 0 && a[pos-1] == p - 1) pos--;
        if(pos < n-1)
            add(0);
        if(pos > 0)
            add(a[pos - 1] + 1);
        else 
            add(1);
    }
    for(int i = 0; i < n - 1; i++)
        add(a[i]);
    return rem == 0;
}

int32_t main(){
    
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> p;
        vector<int> a(n);
        for(int i = 0; i < n; i++)
            cin >> a[i];
        int l = -1, r = p-1;
        while(r - l > 1) {
            int m = (l+r)/2;
            if(check(a, m))
                r = m;
            else 
                l = m;
        }
        cout << r << '\n';
    }    

    return 0;
}
