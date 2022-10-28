#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)v.size()

using Graph = vector<vector<int>>;

struct LCA {
  vector<vector<int>> doubling; // doubling[k][i] : iの2^k先の親
  vector<int> dist;
  LCA(const Graph& G, int root = 0) { init(G, root); }

  void init(const Graph& G, int root) {
    int V = (int)G.size();
    int K = 1;
    while ((1 << K) < V)
      K++;
    doubling.assign(K, vector<int>(V, -1));
    dist.assign(V, -1);
    dfs(G, root, -1, 0);
    for (int k = 1; k < K; k++) {
      for (int i = 0; i < V; i++) {
        if (doubling[k - 1][i] != -1)
          doubling[k][i] = doubling[k - 1][doubling[k - 1][i]];
      }
    }
  }

  void dfs(const Graph& G, int u, int p, int d) {
    doubling[0][u] = p;
    dist[u] = d;
    for (auto v : G[u]) {
      if (v != p) dfs(G, v, u, d + 1);
    }
  }

  int lca(int u, int v) {
    if (dist[u] < dist[v]) swap(u, v);
    // dist[u] >= dist[v]
    int K = (int)doubling.size();
    for (int k = 0; k < K; k++) {
      if (((dist[u] - dist[v]) >> k) & 1) u = doubling[k][u];
    }
    if (u == v) return u;
    for (int k = K - 1; k >= 0; k--) {
      if (doubling[k][u] != doubling[k][v]) {
        u = doubling[k][u];
        v = doubling[k][v];
      }
    }
    return doubling[0][u];
  }
};

int main() {
  int n;
  cin >> n;
  Graph G(n);
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    for (int j = 0; j < k; j++) {
      int c;
      cin >> c;
      G[i].push_back(c);
    }
  }

  LCA tree(G);

  int q;
  cin >> q;
  while (q--) {
    int u, v;
    cin >> u >> v;
    cout << tree.lca(u, v) << endl;
  }
}

// 検証用：https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C&lang=ja