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
  ll N = input();
  vector<ll> P = input(N);

  vector<pair<char, ll>> ans;

  REP(i, N) {
    REP(j, N) {
      if (j + 2 >= N) continue;
      if ((P[j + 2] - 1) % 2 != j % 2 && (P[j] - 1) % 2 == j % 2) {
        swap(P[j], P[j + 2]);
        ans.push_back({'B', j});
      }
    }
  }

  vector<ll> od;
  vector<ll> ev;

  REP(i, N) {
    if ((P[i] - 1) % 2 != i % 2) {
      if (P[i] % 2 == 0) ev.push_back(i);
      else od.push_back(i);
    }
  }

  deb(od);
  deb(ev);

  REP(i, SZ(od)) {
    ll o = od[i];
    ll e = ev[i];
    if (e < o) {
      while (e + 1 != o) {
        swap(P[o], P[o - 2]);
        o -= 2;
        ans.push_back({'B', o - 2});
      }
      swap(P[e], P[o]);
      ans.push_back({'A', e});
    } else { // e > o
      while (o + 1 != e) {
        swap(P[e], P[e - 2]);
        e -= 2;
        ans.push_back({'B', e - 2});
      }
      swap(P[e], P[o]);
      ans.push_back({'A', o});
    }
  }

  deb(P);
  // deb(ans);

  REP(i, 0, N, 2) {
    REP(j, 0, N, 2) {
      if (j + 2 >= N) continue;
      if (P[j] > P[j + 2]) {
        swap(P[j], P[j + 2]);
        ans.push_back({'B', j});
      }
    }
  }

  REP(i, 1, N, 2) {
    REP(j, 1, N, 2) {
      if (j + 2 >= N) continue;
      if (P[j] > P[j + 2]) {
        swap(P[j], P[j + 2]);
        ans.push_back({'B', j});
      }
    }
  }

  deb(P);

  cout << SZ(ans) << endl;
  for (auto [c, pos] : ans) {
    cout << c << " " << pos + 1 << '\n';
  }
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