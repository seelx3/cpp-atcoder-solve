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

#define INF (ll)1e18

int main() {
  ll H, W, rs, cs;
  cin >> H >> W >> rs >> cs;
  map<ll, set<ll>> yoko, tate;
  ll N = input();
  REP(_, N) {
    ll r, c;
    cin >> r >> c;
    yoko[r].insert(c);
    tate[c].insert(r);
  }

  for (auto [x, _] : yoko) {
    yoko[x].insert(-1);
    yoko[x].insert(INF);
  }
  for (auto [x, _] : tate) {
    tate[x].insert(-1);
    tate[x].insert(INF);
  }

  ll nowy = rs; // 行
  ll nowx = cs; // 列

  ll Q = input();
  REP(_, Q) {
    char d = input();
    ll l = input();

    ll nxy = nowy;
    ll nxx = nowx;

    if (d == 'U') {
      nxy = max(1LL, nowy - l);
      if (tate.count(nowx)) {
        auto it = tate[nowx].lower_bound(nowy);
        it = prev(it);
        if (it != tate[nowx].begin() && it != tate[nowx].end()) {
          chmax(nxy, *it + 1);
        }
      }
    } else if (d == 'D') {
      nxy = min(H, nowy + l);
      if (tate.count(nowx)) {
        auto it = tate[nowx].lower_bound(nowy);
        if (it != tate[nowx].begin() && it != tate[nowx].end()) {
          chmin(nxy, *it - 1);
        }
      }
    } else if (d == 'L') {
      nxx = max(1LL, nowx - l);
      if (yoko.count(nowy)) {
        auto it = yoko[nowy].lower_bound(nowx);
        it = prev(it);
        if (it != yoko[nowy].begin() && it != yoko[nowy].end()) {
          chmax(nxx, *it + 1);
        }
      }
    } else if (d == 'R') {
      nxx = min(W, nowx + l);
      if (yoko.count(nowy)) {
        auto it = yoko[nowy].lower_bound(nowx);
        if (it != yoko[nowy].begin() && it != yoko[nowy].end()) {
          chmin(nxx, *it - 1);
        }
      }
    }

    nowy = nxy;
    nowx = nxx;

    cout << nowy << ' ' << nowx << '\n';
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