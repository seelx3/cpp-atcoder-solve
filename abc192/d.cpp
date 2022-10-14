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

// a + b がオーバーフローするならtrueを返す
template <class T> bool overflow_if_add(T a, T b) {
  return (std::numeric_limits<T>::max() - a) < b;
}

// a * b がオーバーフローするならtrueを返す
template <class T> bool overflow_if_mul(T a, T b) {
  return (std::numeric_limits<T>::max() / a) < b;
}

int main() {
  string X = input();
  ll M = input();
  reverse(ALL(X));

  if (SZ(X) == 1) {
    cout << (M >= (ll)(X[0] - '0')) << '\n';
    return 0;
  }

  ll d = 0;
  REP(i, SZ(X)) chmax(d, (ll)(X[i] - '0'));

  ll l = 0, r = (ll)1e18 + 1;

  auto f = [&](ll x) -> bool {
    ll val = 0;
    ll y = 1;
    REP(i, SZ(X)) {
      if (X[i] != '0') {
        ll c = (ll)(X[i] - '0');
        if (overflow_if_mul(c, y)) return false;
        ll tmp = c * y;
        if (overflow_if_add(val, tmp)) return false;
        val += tmp;
      }
      if (i < SZ(X) - 1) {
        if (overflow_if_mul(y, x)) return false;
        y *= x;
      }
    }
    if (val <= M) return true;
    else return false;
  };

  while (l + 1 < r) {
    ll m = (l + r) / 2;
    // m 進数で x は M 以下 -> l = m
    // else -> r = m
    if (f(m)) {
      l = m;
    } else {
      r = m;
    }
  }

  cout << max(0LL, l - d) << '\n';
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