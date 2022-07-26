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

using mint = modint;

int main() {
  ll N = input();
  ll P = input();
  mint::set_mod(P);

  auto dp = make_vec(N + 5, N + 5, (mint)0);
  dp[0][0] = 1;

  auto ten_shift = [](int n) {
    ll ret = 1;
    while (n--)
      ret *= 10;
    return ret;
  };

  auto sum = make_vec(N + 5, N + 5, (mint)0);
  REP(j, N) {
    REP(i, N + 1) {
      if (i) sum[i][j] += sum[i - 1][j];
      dp[i][j] += sum[i][j];
    }
    REP(i, N) {
      // 1 <= k <= min(N - i, ten_shift(N-j-1) - 1)
      // O(N^3)の解法でのkの取りうる最大値を求める
      ll mx_k = min(N - i, ten_shift(min(N - j - 1, 4LL)) - 1);
      REP(len_k, 1, 5) { // 1 ~ 4
        // 桁数len_kで取りうる最小値l・最大値r
        ll l = ten_shift(len_k - 1);
        ll r = min(ten_shift(len_k) - 1, mx_k);
        if (l > mx_k) break;
        if (i == 0 && j == 0) {
          // dp[i+l ~ i+r][j+1+len_k] に加算
          sum[i + l][j + 1 + len_k] += dp[i][j] * 26;
          sum[i + r + 1][j + 1 + len_k] -= dp[i][j] * 26;
        } else {
          sum[i + l][j + 1 + len_k] += dp[i][j] * 25;
          sum[i + r + 1][j + 1 + len_k] -= dp[i][j] * 25;
        }
      }
    }
  }

  mint ans = 0;
  REP(i, N) { ans += dp[N][i]; }

  cout << ans.val() << '\n';
}

/*-----------------------------------------------------------
// O(N^3) ver
REP(j, N) {
  REP(i, N) {
    REP(k, 1, N + 1) {
      int len_k = len(k);
      if (i + k > N || j + 1 + len_k > N) continue;
      dp[i + k][j + 1 + len_k] += dp[i][j] * (i == 0 && j == 0 ? 26 : 25);
    }
  }
}
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