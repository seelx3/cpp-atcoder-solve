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

using mint = modint998244353;

int main() {
  ll N = input();
  vector<ll> p = input(N);
  vector<ll> q = input(N);

  dsu uf(N);
  REP(i, N) { uf.merge(p[i] - 1, q[i] - 1); }

  auto dp1 = make_vec(N, 2, (mint)0);
  auto dp2 = make_vec(N, 2, (mint)0);

  dp1[0][0] = 1;
  dp1[0][1] = 0;
  REP(i, 1, N) {
    dp1[i][0] = dp1[i - 1][1];
    dp1[i][1] = dp1[i - 1][0] + dp1[i - 1][1];
  }

  dp2[0][0] = 0;
  dp2[0][1] = 1;
  REP(i, 1, N) {
    dp2[i][0] = dp2[i - 1][1];
    dp2[i][1] = dp2[i - 1][0] + dp2[i - 1][1];
  }

  mint ans = 1;

  vector<bool> seen(N);
  REP(i, N) {
    int leader = uf.leader(i);
    if (seen[leader]) continue;

    int sz = uf.size(leader);
    mint tmp = dp1[sz - 1][1] + dp2[sz - 1][0] + dp2[sz - 1][1];
    deb(dp1[sz - 1][1].val());
    deb(dp2[sz - 1][0].val());
    deb(dp2[sz - 1][1].val());
    ans *= tmp;

    seen[leader] = true;
  }

  cout << ans.val() << '\n';
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