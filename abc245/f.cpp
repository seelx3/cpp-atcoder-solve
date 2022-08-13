#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)v.size()

/**
 * keyword: 強連結成分分解
 *
 * 大きさが2以上の強連結成分から
 * 有向辺の向きを逆にして到達することができる
 * 頂点の個数を求める
 */

template <typename T> struct edge {
  int src, to;
  T cost;

  edge(int to, T cost) : src(-1), to(to), cost(cost) {}

  edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}

  edge& operator=(const int& x) {
    to = x;
    return *this;
  }

  operator int() const { return to; }
};

template <typename T> using Edges = vector<edge<T>>;
using UnWeightedGraph = vector<vector<int>>;

template <typename G> struct StronglyConnectedComponents {
  const G& g;
  UnWeightedGraph gg, rg;
  vector<int> comp, order, used;

  StronglyConnectedComponents(G& g)
      : g(g), gg(g.size()), rg(g.size()), comp(g.size(), -1), used(g.size()) {
    for (int i = 0; i < g.size(); i++) {
      for (auto e : g[i]) {
        gg[i].emplace_back((int)e);
        rg[(int)e].emplace_back(i);
      }
    }
  }

  int operator[](int k) { return comp[k]; }

  void dfs(int idx) {
    if (used[idx])
      return;
    used[idx] = true;
    for (int to : gg[idx])
      dfs(to);
    order.push_back(idx);
  }

  void rdfs(int idx, int cnt) {
    if (comp[idx] != -1)
      return;
    comp[idx] = cnt;
    for (int to : rg[idx])
      rdfs(to, cnt);
  }

  void build(UnWeightedGraph& t) {
    for (int i = 0; i < gg.size(); i++)
      dfs(i);
    reverse(begin(order), end(order));
    int ptr = 0;
    for (int i : order)
      if (comp[i] == -1)
        rdfs(i, ptr), ptr++;

    t.resize(ptr);
    for (int i = 0; i < g.size(); i++) {
      for (auto& to : g[i]) {
        int x = comp[i], y = comp[to];
        if (x == y)
          continue;
        t[x].push_back(y);
      }
    }
  }
};

int main() {
  ll n, m;
  cin >> n >> m;
  UnWeightedGraph g(n), buff, rev_g(n);
  for (int i = 0; i < m; i++) {
    ll u, v;
    cin >> u >> v;
    u--;
    v--;
    g[u].emplace_back(v);
    rev_g[v].emplace_back(u);
  }

  StronglyConnectedComponents<UnWeightedGraph> scc(g);
  scc.build(buff);

  map<int, int> scc_sz;
  // mp[i] := i番目の強連結成分の頂点数
  for (int i = 0; i < n; i++) {
    scc_sz[scc[i]]++;
  }

  vector<bool> seen(n);
  int ans = 0;

  function<void(int)> dfs = [&](int u) -> void {
    for (auto v : rev_g[u]) {
      if (seen[v])
        continue;
      seen[v] = true;
      ans++;
      dfs(v);
    }
  };

  for (int i = 0; i < n; i++) {
    if (seen[i] || scc_sz[scc[i]] < 2)
      continue;
    dfs(i);
  }

  cout << ans << endl;

#ifdef DEBUG
  for (int i = 0; i < n; i++) {
    cout << i << " : " << scc[i] << " " << seen[i] << endl;
  }
#endif
}
