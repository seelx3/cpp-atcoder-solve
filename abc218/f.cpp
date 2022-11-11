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

using Graph = vector<vector<int>>;
using P = pair<int, int>;
#define INF (int)1e9

int main() {
  int N, M;
  cin >> N >> M;

  Graph G(N);
  vector<int> a(M), b(M);
  for (int i = 0; i < M; i++) {
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
    G[a[i]].push_back(b[i]);
  }

  vector<int> prev(N, -1);
  vector<int> dist(N, INF);
  dist[0] = 0;

  priority_queue<P, vector<P>, greater<P>> pq;
  pq.push({0, 0});

  while (!pq.empty()) {
    auto [d, v] = pq.top();
    pq.pop();

    if (dist[v] < d) continue;

    for (auto nv : G[v]) {
      if (dist[nv] > d + 1) {
        dist[nv] = d + 1;
        prev[nv] = v;
        pq.push({dist[nv], nv});
      }
    }
  }

  set<P> used_edge;
  {
    int v = N - 1;
    while (v != 0) {
      int pv = prev[v];
      used_edge.insert({pv, v});
      v = pv;
    }
  }

  deb(dist);
  deb(used_edge);

  int normal_dist = dist[N - 1];

  auto dist_except = [&](int s, int t) {
    fill(ALL(dist), INF);
    dist[0] = 0;

    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0, 0});

    while (!pq.empty()) {
      auto [d, v] = pq.top();
      pq.pop();

      if (dist[v] < d) continue;

      for (auto nv : G[v]) {
        if (v == s && nv == t) continue;
        if (dist[nv] > d + 1) {
          dist[nv] = d + 1;
          pq.push({dist[nv], nv});
        }
      }
    }

    return (dist[N - 1] == INF) ? -1 : dist[N - 1];
  };

  REP(i, M) {
    if (used_edge.count({a[i], b[i]})) {
      cout << dist_except(a[i], b[i]) << '\n';
    } else {
      cout << (normal_dist == INF ? -1 : normal_dist) << '\n';
    }
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