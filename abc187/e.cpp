#ifndef INCLUDED_MAIN
#define INCLUDED_MAIN

#include <bits/stdc++.h>
using namespace std;

#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define SZ(v) (int)(v.size())

#include __FILE__

// 木dp

int main() {
  ll N = input();
  Graph G(N);

  vector<int> a(N - 1), b(N - 1);

  REP(i, N - 1) {
    cin >> a[i] >> b[i];
    a[i]--, b[i]--;

    G[a[i]].push_back(b[i]);
    G[b[i]].push_back(a[i]);
  }

  LCA tree(G, 0);

  vector<ll> dp(N);

  int Q = input();
  while (Q--) {
    int t, e, x;
    cin >> t >> e >> x;
    e--;
    int u = a[e], v = b[e];
    if (t == 2) swap(u, v);
    if (tree.lca(u, v) == u) {
      dp[0] += x;
      dp[v] -= x;
    } else {
      dp[u] += x;
    }
  }

  function<void(int, int)> dfs = [&](int u, int par) -> void {
    deb(u);
    for (auto v : G[u]) {
      if (v == par) continue;
      dp[v] += dp[u];
      dfs(v, u);
    }
  };

  dfs(0, 0);

  REP(i, N) cout << dp[i] << '\n';
}

/*-----------------------------------------------------------
-----------------------------------------------------------*/

#else // INCLUDED_MAIN

// clang-format off
#define cauto const auto&

#define OVERLOAD_REP(_1, _2, _3, _4, name, ...) name
#define REP1(i, n) REP3(i, 0, n, 1)
#define REP2(i, a, b) REP3(i, a, b, 1)
#define REP3(i, a, b, c) for (int i = int(a); i < int(b); i += c)
#define REP(...) OVERLOAD_REP(__VA_ARGS__, REP3, REP2, REP1, )(__VA_ARGS__)

#define OVERLOAD_REPR(_1, _2, _3, _4, name, ...) name
#define REPR1(i, n) REPR3(i, 0, n, 1)
#define REPR2(i, a, b) REPR3(i, a, b, 1)
#define REPR3(i, a, b, c) for (int i = int(b) - 1; i >= int(a); i -= c)
#define REPR(...) OVERLOAD_REPR(__VA_ARGS__, REPR3, REPR2, REPR1, )(__VA_ARGS__)

#define OVERLOAD_REPE(_1, _2, _3, _4, name, ...) name
#define REPE1(i, n) REPE3(i, 0, n, 1)
#define REPE2(i, a, b) REPE3(i, a, b, 1)
#define REPE3(i, a, b, c) for (int i = int(a); i <= int(b); i += c)
#define REPE(...) OVERLOAD_REPE(__VA_ARGS__, REPE3, REPE2, REPE1, )(__VA_ARGS__)

#define OVERLOAD_REPRE(_1, _2, _3, _4, name, ...) name
#define REPRE1(i, n) REPRE3(i, 0, n, 1)
#define REPRE2(i, a, b) REPRE3(i, a, b, 1)
#define REPRE3(i, a, b, c) for (int i = int(b); i >= int(a); i -= c)
#define REPRE(...) OVERLOAD_REPRE(__VA_ARGS__, REPRE3, REPRE2, REPE1, )(__VA_ARGS__)

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

template< typename T, typename U >
static inline vector<U> make_vec(T&& n, U&& val) noexcept {
  return vector<U>(forward<T>(n), forward<U>(val)); 
}
template< typename T, typename... Args >
static inline decltype(auto) make_vec(T&& n, Args&&... args) noexcept {
  return vector<decltype(make_vec(forward<Args>(args)...))>(forward<T>(n), make_vec(forward<Args>(args)...));
}

struct input { 
  int n; input() {} input(int n_) : n(n_){};
  template <class T> operator T() { T ret; cin >> ret; return ret; }
  template <class T> operator vector<T>() { vector<T> ret(n); for (int i = 0; i < n; i++) cin >> ret[i]; return ret; }
};
// clang-format on

#ifdef LOCAL
#include <debug.hpp>
#define deb(...) debug::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define deb(...) (static_cast<void>(0))
#endif

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

#endif // INCLUDED_MAIN