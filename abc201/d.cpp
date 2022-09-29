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

#define INF (ll)1e10

int main() {
  int H = input();
  int W = input();

  vector<string> a = input(H);

  // (i, j)から(H-1, W-1)までで得られる高橋の得点-青木の得点の最大値
  auto dp = make_vec(H, W, 0LL); // Takahashi

  dp[H - 1][W - 1] = 0;

  REPR(i, H) {
    REPR(j, W) {
      if (i == H - 1 && j == W - 1) continue;
      if ((i + j) % 2 == 0) {
        dp[i][j] = -INF;
        if (j + 1 < W)
          chmax(dp[i][j], dp[i][j + 1] + (a[i][j + 1] == '+' ? 1 : -1));
        if (i + 1 < H)
          chmax(dp[i][j], dp[i + 1][j] + (a[i + 1][j] == '+' ? 1 : -1));
      } else {
        dp[i][j] = INF;
        if (j + 1 < W)
          chmin(dp[i][j], dp[i][j + 1] + (a[i][j + 1] == '+' ? -1 : 1));
        if (i + 1 < H)
          chmin(dp[i][j], dp[i + 1][j] + (a[i + 1][j] == '+' ? -1 : 1));
      }
    }
  }

  deb(dp);

  if (dp[0][0] == 0) cout << "Draw\n";
  else { cout << (dp[0][0] > 0 ? "Takahashi" : "Aoki") << '\n'; }
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