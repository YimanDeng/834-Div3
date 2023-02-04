#include <iostream>
#include <vector>
using namespace std;

int n; // number of vertices
vector<vector<int>> adj; // adjacency list of graph
vector<bool> visited;
vector<int> ans;

void dfs(int v) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u]) 
            dfs(u);
    }
    ans.push_back(v); // post-order
}

/*
main: initializes DFS variables, launches DFS, receives answer in vector `ans`
*/
int main() {
    visited.assign(n, false); // assign(int size, int value)
    ans.clear(); // if answer in form of vector, good practice to clear it for each test
    for (int i=0; i<n; i++) { // graph may not be connected
        if (!visited[i])
            dfs(i);
    }
    reverse(ans.begin(), ans.end());

    return 0;
}
