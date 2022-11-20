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
  int H, W, N, h, w;
  cin >> H >> W >> N >> h >> w;

  vector<vector<int>> A(H, vector<int>(W));
  REP(i, H) REP(j, W) cin >> A[i][j];

  vector<vector<int>> ans(H - h + 1, vector<int>(W - w + 1));
  vector<vector<int>> cnt(H - h + 1, vector<int>(N + 1));

  // STEP1. 愚直にans[0][0]を求める
  REP(i, H) REP(j, W) {
    if (i < h && j < w) continue;
    cnt[0][A[i][j]]++;
  }
  REP(i, 1, N + 1) if (cnt[0][i] > 0) ans[0][0]++;

  // STEP2. ans[i][0]を求める
  REP(i, 1, H - h + 1) {
    REP(j, N + 1) cnt[i][j] = cnt[i - 1][j];
    REP(j, w) {
      cnt[i][A[i - 1][j]]++;
      cnt[i][A[i + h - 1][j]]--;
    }
    REP(j, 1, N + 1) if (cnt[i][j] > 0) ans[i][0]++;
  }

  // STEP3. ans[i][j]を求める
  REP(i, H - h + 1)
  REP(j, 1, W - w + 1) {
    REP(k, h) {
      cnt[i][A[i + k][j - 1]]++;
      cnt[i][A[i + k][j + w - 1]]--;
    }
    REP(k, 1, N + 1) if (cnt[i][k] > 0) ans[i][j]++;
  }

  deb(ans);

  REP(i, H - h + 1) {
    REP(j, W - w + 1) cout << ans[i][j] << " \n"[j == W - w];
  }
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

#endif // INCLUDED_MAIN