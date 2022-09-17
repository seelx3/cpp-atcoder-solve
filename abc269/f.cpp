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
  ll M = input();
  int Q = input();

  while (Q--) {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    mint ans = 0;

    // 偶数行
    ll evenrow_cnt = b / 2 - (a - 1) / 2;
    ll evencolumn_cnt = d / 2 - (c - 1) / 2;
    mint ev = 0;
    REP(i, 2) REP(j, 2) {
      if (!(a + i <= b && c + j <= d)) continue;
      if (((a + i) + (c + j)) % 2 == 0 && (a + i) % 2 == 0)
        ev = ((a + i) - 1) * M + (c + j);
    }

    ev = evenrow_cnt * (2 * ev + (evenrow_cnt - 1) * 2 * M) / 2;
    ev = evencolumn_cnt * (2 * ev + (evencolumn_cnt - 1) * evenrow_cnt * 2) / 2;
    ans += ev;

    // 奇数行
    ll oddrow_cnt = (b - a + 1) - evenrow_cnt;
    ll oddcolumn_cnt = (d - c + 1) - evencolumn_cnt;
    mint od = 0;
    REP(i, 2) REP(j, 2) {
      if (!(a + i <= b && c + j <= d)) continue;
      if (((a + i) + (c + j)) % 2 == 0 && (a + i) % 2 != 0)
        od = ((a + i) - 1) * M + (c + j);
    }

    od = oddrow_cnt * (2 * od + (oddrow_cnt - 1) * 2 * M) / 2;
    od = oddcolumn_cnt * (2 * od + (oddcolumn_cnt - 1) * oddrow_cnt * 2) / 2;
    ans += od;

    deb(ev.val(), od.val());

    cout << ans.val() << endl;
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