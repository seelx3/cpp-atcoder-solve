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

// clang-format off
int main() {
  int N = input();
  vector<int> P = input(N);
  vector<int> I = input(N);

  vector<int> pid(N + 1, -1), iid(N + 1, -1);
  REP(i, N) {
    pid[P[i]] = i;
    iid[I[i]] = i;
  }

  vector<pair<int, int>> G(N + 1);
  // G[i].first  := 左の子
  // G[i].second := 右の子

  function<int(int, int, int)> dfs = [&](int u, int l, int r) -> int {
    int ppos = pid[u];
    int step = 0;

    // left : l ~ iid[u]
    if (ppos + 1 < N && l <= iid[P[ppos + 1]] && iid[P[ppos + 1]] < iid[u]) {
      G[u].first = P[ppos + 1];
      step += dfs(P[ppos + 1], l, iid[u]);
    }

    // right: iid[u]+1 ~ r
    ppos += step;
    if (ppos + 1 < N && iid[u] + 1 <= iid[P[ppos + 1]] && iid[P[ppos + 1]] < r) {
      G[u].second = P[ppos + 1];
      step += dfs(P[ppos + 1], iid[u] + 1, r);
    }

    return step + 1;
  };

  dfs(1, 0, N);
  deb(G);

  // 1を根とする二分木になっているかどうかcheck
  int cnt = 0;
  REP(i, 1, N + 1) {
    if (G[i].first != 0) cnt++;
    if (G[i].second != 0) cnt++;
  }

  if (cnt != N - 1) {
    cout << "-1\n";
  } else {
    REP(i, 1, N + 1) { cout << G[i].first << ' ' << G[i].second << '\n'; }
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