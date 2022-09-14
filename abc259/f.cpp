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
// dp_leq[u] =
// uを根とする部分木から辺を選択、uに接続する辺をd_u本"以下"選択したときの最大値
// dp_le[u]  =
// uを根とする部分木から辺を選択、uに接続する辺をd_u本"未満"選択したときの最大値

struct edge {
  int to;
  ll weight;
};

using Graph = vector<vector<edge>>;

#define INF (ll)(1e12)

int main() {
  int N = input();
  vector<int> d = input(N);
  Graph G(N);
  REP(i, N - 1) {
    int u = (int)input() - 1;
    int v = (int)input() - 1;
    ll w = input();
    G[u].push_back({v, w});
    G[v].push_back({u, w});
  }

  vector<ll> dp_leq(N), dp_le(N);

  function<void(int, int)> dfs = [&](int u, int par) -> void {
    vector<pair<ll, int>> D;
    for (auto v : G[u]) {
      if (v.to == par) continue;
      dfs(v.to, u);
      D.emplace_back(dp_le[v.to] + v.weight - dp_leq[v.to], v.to);
    }
    sort(ALL(D), greater<>());
    REP(i, SZ(D)) {
      // dp_le
      if (i < d[u] - 1) {
        if (D[i].first > 0)
          dp_le[u] += D[i].first + dp_leq[D[i].second]; // 選択する
        else dp_le[u] += dp_leq[D[i].second];           // 選択しない
      } else {
        dp_le[u] += dp_leq[D[i].second];
      }

      // dp_leq
      if (i < d[u]) {
        if (D[i].first > 0)
          dp_leq[u] += D[i].first + dp_leq[D[i].second]; // 選択する
        else dp_leq[u] += dp_leq[D[i].second];           // 選択しない
      } else {
        dp_leq[u] += dp_leq[D[i].second];
      }
    }
    if (d[u] == 0) { dp_le[u] = -INF; }
  };

  dfs(0, -1);
  cout << dp_leq[0] << endl;
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