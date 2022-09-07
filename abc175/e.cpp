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
  int R, C, K;
  cin >> R >> C >> K;
  // dp[i][j][k] := (i,
  // j)にたどり着くときの価値の合計の最大値、kはその行でアイテムを拾った回数
  auto dp = make_vec(R, C, 4, 0LL);
  auto item = make_vec(R, C, 0LL);
  REP(i, K) {
    ll r, c, v;
    cin >> r >> c >> v;
    r--;
    c--;
    item[r][c] = v;
  }

  // 配るdp
  REP(i, R) {
    REP(j, C) {
      REP(k, 4) { // k: 0 ~ 3
        if (item[i][j] && k < 3) {
          if (j + 1 < C) chmax(dp[i][j + 1][k + 1], dp[i][j][k] + item[i][j]);
          if (i + 1 < R) chmax(dp[i + 1][j][0], dp[i][j][k] + item[i][j]);
        }
        if (j + 1 < C) chmax(dp[i][j + 1][k], dp[i][j][k]);
        if (i + 1 < R) chmax(dp[i + 1][j][0], dp[i][j][k]);
      }
    }
  }

  deb(item);

  ll ans = 0;
  REP(k, 4) {
    chmax(ans, dp[R - 1][C - 1][k] + (k < 3 ? item[R - 1][C - 1] : 0LL));
  }

  cout << ans << endl;
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