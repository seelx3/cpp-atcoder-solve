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

void ok(const vector<int>& v1, const vector<int>& v2) {
  cout << "Yes\n";
  cout << SZ(v1) << ' ';
  REP(i, SZ(v1)) cout << v1[i] << " \n"[i == SZ(v1) - 1];
  cout << SZ(v2) << ' ';
  REP(i, SZ(v2)) cout << v2[i] << " \n"[i == SZ(v2) - 1];
  exit(0);
};

int main() {
  int N = input();
  vector<ll> A = input(N);

  // dp[i][j] : i番目まで見たとき、和 mod 200 がjとなるような数列

  vector<vector<vector<vector<int>>>> dp(N + 1,
                                         vector<vector<vector<int>>>(200));

  REP(i, N) {
    REP(j, 200) dp[i + 1][j] = dp[i][j];
    REP(j, 200) {
      if (SZ(dp[i][j]) == 0) continue;
      auto tmp = dp[i][j][0];
      tmp.push_back(i + 1);
      dp[i + 1][(j + A[i] + 200) % 200].push_back(tmp);
      auto ans = dp[i + 1][(j + A[i] + 200) % 200];
      if (SZ(ans) == 2) { ok(ans[0], ans[1]); }
    }
    dp[i + 1][A[i] % 200].push_back({i + 1});
    auto ans = dp[i + 1][A[i] % 200];
    if (SZ(ans) == 2) { ok(ans[0], ans[1]); }
  }

  cout << "No\n";
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