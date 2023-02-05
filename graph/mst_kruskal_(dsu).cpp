#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int u; int v; int w;
  bool operator<(Edge const &other_edge) const {
    return w < other_edge.w;
  }
};

vector<Edge> graph;
vector<int> sz, parent;
vector<Edge> result;

int get(int v) {
  return parent[v] = (parent[v] == v) ? v : get(parent[v]);
}

void unite(int u, int v) {
  u = get(u); v = get(v);
  if (u != v) {
    if (sz[u] < sz[v])
      swap(u, v);
    parent[v] = u;
    sz[u] += sz[v];
  }
}

int main() {
  int n, m; cin >> n >> m; // num of nodes and edges
  sz.resize(n); parent.resize(n);

  while (m--) {
    Edge e; cin >> e.u >> e.v >> e.w; // u, v, w
    e.u--, e.v--; // assume input is 1-indexed
    graph.push_back(e);
  }
  
  // make set
  for (int i=0; i<n; i++) {
    sz[i] = 1; parent[i] = i;
  }
  
  // sort edges according to weight
  sort(graph.begin(), graph.end());
  
  // merge nodes until selected set at size n-1
  
  for (int i=0; i <n-1; i++) {
    Edge e = graph[i];
    if (get(e.u) != get(e.v)) { // nodes on 2 side of edge in different sets
      result.push_back(e);
      unite(e.u, e.v);
    }
  }

  // print out selected set
  for (Edge e : result) {
    cout << e.u+1 << "-" << e.v+1 << endl;
  }
  
  return 0;
}
