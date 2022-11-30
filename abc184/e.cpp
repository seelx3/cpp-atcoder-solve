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

#define INF (int)1e9
using WeitedGraph = vector<vector<pair<int, int>>>;

int main() {
  int H, W;
  cin >> H >> W;
  vector<string> a(H);
  REP(i, H) cin >> a[i];

  WeitedGraph G(H * W + 26);
  int s = -1, g = -1;
  REP(i, H) {
    REP(j, W) {
      ll v = i * W + j;
      if (a[i][j] == 'S') s = v;
      if (a[i][j] == 'G') g = v;
      if (a[i][j] == '#') continue;
      if (i + 1 < H && a[i + 1][j] != '#') {
        G[v].emplace_back(v + W, 2);
        G[v + W].emplace_back(v, 2);
      }
      if (j + 1 < W && a[i][j + 1] != '#') {
        G[v].emplace_back(v + 1, 2);
        G[v + 1].emplace_back(v, 2);
      }
      if (a[i][j] >= 'a' && a[i][j] <= 'z') {
        G[v].emplace_back(H * W + a[i][j] - 'a', 1);
        G[H * W + a[i][j] - 'a'].emplace_back(v, 1);
      }
    }
  }

  vector<int> dist(H * W + 26, INF);
  dist[s] = 0;

  deque<pair<int, int>> dq;
  dq.push_front({s, 0});

  while (!dq.empty()) {
    auto [u, d] = dq.front();
    dq.pop_front();
    if (dist[u] < d) continue;
    for (auto [v, w] : G[u]) {
      if (dist[v] > dist[u] + w) {
        dist[v] = dist[u] + w;
        if (w == 1) {
          dq.push_front({v, dist[v]});
        } else {
          dq.push_back({v, dist[v]});
        }
      }
    }
  }

  deb(s, g, dist);
  cout << (dist[g] == INF ? -1 : dist[g] / 2) << '\n';
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