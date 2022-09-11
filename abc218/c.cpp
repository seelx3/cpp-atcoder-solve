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
  vector<string> s = input(N);
  vector<string> t = input(N);

  int us = N, ds = -1, ls = N, rs = -1;
  REP(i, N) REP(j, N) {
    if (s[i][j] == '#') {
      chmin(us, i);
      chmax(ds, i);
      chmin(ls, j);
      chmax(rs, j);
    }
  }

  int ut = N, dt = -1, lt = N, rt = -1;
  REP(i, N) REP(j, N) {
    if (t[i][j] == '#') {
      chmin(ut, i);
      chmax(dt, i);
      chmin(lt, j);
      chmax(rt, j);
    }
  }

  vector<string> ss, tt;

  REP(i, N) {
    if (i >= us && i <= ds) ss.push_back(s[i].substr(ls, rs - ls + 1));
    if (i >= ut && i <= dt) tt.push_back(t[i].substr(lt, rt - lt + 1));
  }

  auto rot = [&](const vector<string>& vs) -> vector<string> {
    vector<string> ret(SZ(vs[0]));
    REP(j, SZ(vs[0])) REPR(i, SZ(vs)) { ret[j].push_back(vs[i][j]); }
    return ret;
  };

  bool ok = false;
  REP(i, 4) {
    if (i > 0) ss = rot(ss);
    if (ss == tt) ok = true;
  }

  cout << (ok ? "Yes" : "No") << endl;
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