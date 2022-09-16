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

using Graph = vector<vector<int>>;

#define INF (ll)(1e10)

int main() {
  int N = input();
  int M = input();
  Graph G(N + 1);
  // 頂点0を追加
  REP(i, M) {
    int u = (int)input();
    int v = (int)input();
    if (u != 0) G[u].push_back(v);
    G[v].push_back(u);
  }

  vector<ll> d1(N + 1, INF), dn(N + 1, INF);

  auto bfs = [](Graph& g, int s, vector<ll>& d) -> void {
    queue<int> qu;
    qu.push(s);
    d[s] = 0;
    while (!qu.empty()) {
      int u = qu.front();
      qu.pop();
      for (auto v : g[u]) {
        if (d[v] != INF) continue;
        qu.push(v);
        d[v] = d[u] + 1;
      }
    }
  };

  bfs(G, 1, d1);
  bfs(G, N, dn);

  deb(d1);
  deb(dn);

  REP(i, 1, N + 1) {
    ll ans = INF;
    chmin(ans, d1[N]);
    chmin(ans, min(d1[0], d1[i]) + min(dn[0], dn[i]));
    cout << (ans < INF ? ans : -1) << " \n"[i == N];
  }
}

/*-----------------------------------------------------------
-----------------------------------------------------------*/

#else // INCLUDED_MAIN

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

// clang-format off
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

#endif // INCLUDED_MAIN