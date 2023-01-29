#include<bits/stdc++.h>
using namespace std;

const int N = 1000043;
vector<int> g[N]; // adjacency list

int color[N];
int siz[N]; // results
int cc = 0; // same cc index means reachable to those of same cc
int n, m;

// helper dfs objectives: 
//      for a node, return the size of its component
//      node only count towards size if its a user and not a group
//      for uncolored nodes, color it with the cc
int dfs(int x) {
    if (color[x]) 
        return 0;
    color[x] = cc;
    int ans = (x < n ? 1 : 0);
    for (auto y : g[x]) {
        ans += dfs(y);
    }
    return ans;
}

// n users, m groups of friends
// use dfs or dsu to find components and sizes
// key is to those recheable to one another together
int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) { // i is group index
        int k; 
        cin >> k; // num of ppl in this group
        for (int j = 0; j < k; j++) {
            int x; 
            cin >> x; 
            x--;
            g[x].push_back(n + i); // edge between member and their group num
            g[n + i].push_back(x);
        }
    }

    for (int i = 0; i < n; i++) {
        if (!color[i]) { // no data for this node yet
            cc++;
            siz[cc] = dfs(i);
        }
        cout << siz[color[i]] << " ";
    }

    return 0;
}