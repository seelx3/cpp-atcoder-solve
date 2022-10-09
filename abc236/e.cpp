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
  int N = input();
  vector<int> A = input(N);

  auto check_avg = [&](double k) -> bool {
    vector<double> B(ALL(A));
    REP(i, N) B[i] -= k;
    auto f = make_vec(N + 1, 0.0);
    auto g = make_vec(N + 1, 0.0);
    REP(i, N) {
      f[i + 1] = max(f[i], g[i]) + B[i];
      g[i + 1] = f[i];
    }
    return (max(f[N], g[N]) < 0 ? false : true);
  };

  auto check_med = [&](double k) -> bool {
    vector<int> B(N);
    REP(i, N) B[i] = (A[i] >= k ? 1 : -1);
    auto f = make_vec(N + 1, 0.0);
    auto g = make_vec(N + 1, 0.0);
    REP(i, N) {
      f[i + 1] = max(f[i], g[i]) + B[i];
      g[i + 1] = f[i];
    }
    return (max(f[N], g[N]) <= 0 ? false : true);
  };

  double mx_avg = -1.0;
  int mx_med = -1;

  {
    double l = 1.0;
    double r = 1000000000.0;
    double m = -1.0;

    while ((r - l) / r >= 0.00001) {
      m = (l + r) / 2.0;
      if (check_avg(m)) l = m;
      else r = m;
    }
    mx_avg = l;
  }
  {
    int l = 1;
    int r = 1000000000 + 1;
    int m = -1.0;
    while (l + 1 < r) {
      m = (l + r) / 2;
      if (check_med(m)) l = m;
      else r = m;
    }
    mx_med = l;
  }

  cout << fixed << setprecision(10) << mx_avg << '\n';
  cout << mx_med << '\n';
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