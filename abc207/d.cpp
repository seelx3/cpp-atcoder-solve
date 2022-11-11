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

struct vec {
  int x, y;
};

struct frac {
  int p, q;
  frac(int P = 0, int Q = 1) : p(P), q(Q) {}
  bool operator<(const frac& other) const { return p * other.q < other.p * q; }
  bool operator<=(const frac& other) const {
    return p * other.q <= other.p * q;
  }
  bool operator==(const frac& other) const {
    return p * other.q == other.p * q;
  }
};

int inner_product(vec a, vec b) { return a.x * b.x + a.y * b.y; }

int outer_product(vec a, vec b) { return a.x * b.y - a.y * b.x; }

frac length_ratio(vec a, vec b) {
  return frac{inner_product(a, a), inner_product(b, b)};
}

int main() {
  int N = input();
  vector<int> a(N), b(N), c(N), d(N);
  REP(i, N) cin >> a[i] >> b[i];
  REP(i, N) cin >> c[i] >> d[i];

  set<pair<frac, pair<int, int>>> T;
  // (c1, d1) を中心
  // (c1, d1), (c2, d2) のベクトルを元にする
  vec base = {c[1] - c[0], d[1] - d[0]};
  REP(i, N) {
    vec v = {c[i] - c[0], d[i] - d[0]};
    frac r = length_ratio(v, base);
    T.insert({r, {inner_product(v, base), outer_product(v, base)}});
  }

  bool ok = false;
  REP(i, N) {
    REP(j, N) {
      if (i == j) continue;
      vec bas = {a[j] - a[i], b[j] - b[i]};
      set<pair<frac, pair<int, int>>> S;
      REP(k, N) {
        vec v = {a[k] - a[i], b[k] - b[i]};
        frac r = length_ratio(v, bas);
        S.insert({r, {inner_product(v, bas), outer_product(v, bas)}});
      }
      if (T == S) {
        ok = true;
        break;
      }
    }
  }

  if (N == 1) ok = true;
  cout << (ok ? "Yes" : "No") << endl;
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