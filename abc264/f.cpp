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

#define INF (ll)(1e17)

ll dp[3010][3010][2][2];

ll solve(const vector<string>& A, const vector<ll>& R, const vector<ll>& C) {
  int H = SZ(A);
  int W = SZ(A[0]);
  REP(h, H) REP(w, W) REP(x, 2) REP(y, 2) dp[h][w][x][y] = INF;
  if (A[0][0] == '0') {
    dp[0][0][0][0] = 0;
    dp[0][0][1][1] = R[0] + C[0];
  } else {
    dp[0][0][0][1] = C[0];
    dp[0][0][1][0] = R[0];
  }

  REP(h, H) {
    REP(w, W) {
      REP(x, 2) {
        REP(y, 2) {
          // ↓
          if (h < H - 1) {
            // A[h+1][w]=='0' かつ y==0 or
            // A[h+1][w]=='1' かつ y==1
            if ((A[h + 1][w] == '0') ^ y) {
              chmin(dp[h + 1][w][0][y], dp[h][w][x][y]);
            } else {
              chmin(dp[h + 1][w][1][y], dp[h][w][x][y] + R[h + 1]);
            }
          }

          // →
          if (w < W - 1) {
            if ((A[h][w + 1] == '0') ^ x) {
              chmin(dp[h][w + 1][x][0], dp[h][w][x][y]);
            } else {
              chmin(dp[h][w + 1][x][1], dp[h][w][x][y] + C[w + 1]);
            }
          }
        }
      }
    }
  }

  ll ret = INF;
  REP(i, 2) REP(j, 2) chmin(ret, dp[H - 1][W - 1][i][j]);
  return ret;
};

int main() {
  int H, W;
  cin >> H >> W;
  vector<ll> R = input(H);
  vector<ll> C = input(W);

  vector<string> A = input(H);

  ll ans = INF;
  chmin(ans, solve(A, R, C));
  REP(i, H) REP(j, W) A[i][j] ^= 1;
  chmin(ans, solve(A, R, C));

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