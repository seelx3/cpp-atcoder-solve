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

using UGraph = vector<vector<int>>;

int main() {
  ll n = input();
  ll m = input();
  vector<ll> a = input(n);

  UGraph G(n);

  REP(i, m) {
    int u = (int)input() - 1;
    int v = (int)input() - 1;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  auto cost = make_vec(n, 0LL);
  ll cost_mx = 0;
  REP(u, n) {
    for (auto v : G[u]) {
      cost[u] += a[v];
    }
    chmax(cost_mx, cost[u]);
  }

  auto ok = [&](ll mx) -> bool {
    auto _cost = cost;
    vector<bool> rmvd(n);
    stack<int> stk;
    ll cnt = 0;
    REP(i, n) {
      if (_cost[i] <= mx) {
        stk.push(i);
        rmvd[i] = true;
        cnt++;
      }
    }
    while (!stk.empty()) {
      if (cnt == n) return true;
      int u = stk.top();
      stk.pop();
      for (auto v : G[u]) {
        if (rmvd[v]) continue;
        _cost[v] -= a[u];
        if (_cost[v] <= mx) {
          stk.push(v);
          rmvd[v] = true;
          cnt++;
        }
      }
    }
    return false;
  };

  ll l = -1, r = 1000000000000;
  while (l + 1 < r) {
    ll m = (l + r) / 2;
    if (ok(m)) r = m;
    else l = m;
  }

  cout << r << endl;
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