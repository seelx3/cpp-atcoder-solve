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

int main() {
  int H, W;
  cin >> H >> W;
  ll C = input();
  vector<vector<ll>> A(H, vector<ll>(W));
  REP(i, H) REP(j, W) cin >> A[i][j];

  // N = H*W // 頂点数
  // 愚直解 O(N^2)

  // x1 < x2 && y1 < y2 のとき
  //   A[x1][y1] + A[x2][y2] + C * ((x2 - x1) + (y2 - y1))
  // = (A[x1][y1] - C*(x1 + y1)) + (A[x2][y2] + C*(x2 + y2)) // 座標で分離

  ll ans = (ll)(1e18);

  auto solve = [&]() -> void {
    // dp[i][j] マス(i, j) より左上(マス(i, j)を含む)の範囲における最小値
    auto dp = make_vec(H, W, (ll)(1e18));

    REP(i, H) REP(j, W) {
      chmin(dp[i][j], A[i][j] - C * (i + j));
      if (i) chmin(dp[i][j], dp[i - 1][j]);
      if (j) chmin(dp[i][j], dp[i][j - 1]);
    }

    REP(i, H) REP(j, W) {
      if (i == 0 && j == 0) continue;
      if (i) chmin(ans, A[i][j] + C * (i + j) + dp[i - 1][j]);
      if (j) chmin(ans, A[i][j] + C * (i + j) + dp[i][j - 1]);
    }
  };

  solve();
  REP(i, H) reverse(ALL(A[i]));
  solve();

  cout << ans << endl;
}

/*-----------------------------------------------------------
-----------------------------------------------------------*/

#else // INCLUDED_MAIN

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