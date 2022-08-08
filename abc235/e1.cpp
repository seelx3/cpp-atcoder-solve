#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)v.size()

struct UnionFind {
  vector<int> par;

  UnionFind(int n) : par(n, -1) {}
  void init(int n) { par.assign(n, -1); }

  int root(int x) {
    if (par[x] < 0)
      return x;
    else
      return par[x] = root(par[x]);
  }

  bool issame(int x, int y) { return root(x) == root(y); }

  bool merge(int x, int y) {
    x = root(x);
    y = root(y);
    if (x == y)
      return false;
    if (par[x] > par[y])
      swap(x, y); // merge technique
    par[x] += par[y];
    par[y] = x;
    return true;
  }

  int size(int x) { return -par[root(x)]; }
};

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
      if (v != p)
        dfs(G, v, u, d + 1);
    }
  }

  int lca(int u, int v) {
    if (dist[u] < dist[v])
      swap(u, v);
    // dist[u] >= dist[v]
    int K = (int)doubling.size();
    for (int k = 0; k < K; k++) {
      if (((dist[u] - dist[v]) >> k) & 1)
        u = doubling[k][u];
    }
    if (u == v)
      return u;
    for (int k = K - 1; k >= 0; k--) {
      if (doubling[k][u] != doubling[k][v]) {
        u = doubling[k][u];
        v = doubling[k][v];
      }
    }
    return doubling[0][u];
  }
};

using PI = pair<int, int>;
using PPI = pair<ll, PI>;

int main() {
  int n, m, q;
  cin >> n >> m >> q;

  priority_queue<PPI, vector<PPI>, greater<PPI>> pq;
  for (int i = 0; i < m; i++) {
    int a, b;
    ll c;
    cin >> a >> b >> c;
    a--;
    b--;
    pq.push({c, {a, b}});
  }

  UnionFind uf = UnionFind(n);
  vector<ll> cost(2 * n, -1);
  // 2*n - 2 がrootとなる
  vector<int> parent(2 * n, -1);
  vector<int> root(2 * n, -1);
  for (int i = 0; i < n; i++) {
    root[i] = i;
  }

  int id = n;

  while (!pq.empty()) {
    auto tp = pq.top();
    pq.pop();
    ll c = tp.first;
    int u = tp.second.first, v = tp.second.second;
    if (uf.issame(u, v))
      continue;
    uf.merge(u, v);
    while (parent[root[u]] != -1) {
      root[u] = parent[root[u]];
    }
    while (parent[root[v]] != -1) {
      root[v] = parent[root[v]];
    }
    parent[root[u]] = id;
    parent[root[v]] = id;
    cost[id] = c;
    id++;
  }

  // for (int i = 0; i < 2 * n - 1; i++) {
  //   cout << i + 1 << " : ";
  //   cout << "par = " << parent[i] + 1;
  //   cout << ", cost = " << cost[i] << endl;
  // }

  Graph G(2 * n - 1);
  for (int i = 0; i < 2 * n - 2; i++) {
    G[parent[i]].push_back(i);
  }

  LCA tree = LCA(G, 2 * n - 2);

  while (q--) {
    int u, v;
    ll w;
    cin >> u >> v >> w;
    u--;
    v--;
    if (cost[tree.lca(u, v)] > w)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
}