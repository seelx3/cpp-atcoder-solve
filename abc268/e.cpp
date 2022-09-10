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
  ll n = input();
  vector<ll> p = input(n);

  vector<ll> v(n);
  int mid = (n - 1) / 2;
  REP(i, n) {
    int l = (p[i] - i + n) % n; // 料理iが自分のいくつ左にあるか
    int r = (i - p[i] + n) % n; // 料理iが自分のいくつ右にあるか
    if (l < r) {
      v[mid - l]++;
    } else { // l >= r
      v[mid + r]++;
    }
  }

  ll fumando = 0;
  ll r_num = 0;
  ll l_num = 0;
  REP(i, n) {
    fumando += abs(mid - i) * v[i];
    if (i < mid) l_num += v[i];
    if (i >= mid) r_num += v[i];
  }

  ll ans = fumando;

  deque<ll> dq;
  REP(i, n) dq.push_back(v[i]);

  REP(i, 1, n) { // i: 1 ~ n-1
    ll rtol = dq.back();
    dq.pop_back();
    dq.push_front(rtol);
    if (n % 2 == 0) fumando += -l_num + r_num - 2 * rtol;
    else fumando += -l_num + r_num - rtol;
    chmin(ans, fumando);

    ll gutyoku = 0;
    REP(i, n) { gutyoku += abs(mid - i) * dq[i]; }

    l_num += rtol - dq[mid];
    r_num += -rtol + dq[mid];
  }

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