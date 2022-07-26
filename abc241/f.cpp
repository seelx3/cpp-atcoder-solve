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

ll dx[] = {1, 0, -1, 0};
ll dy[] = {0, 1, 0, -1};

int main() {
  ll H, W, N;
  cin >> H >> W >> N;
  ll sx, sy, gx, gy;
  cin >> sx >> sy >> gx >> gy;

  map<int, set<int>> hor;
  map<int, set<int>> ver;

  REP(i, N) {
    int x, y;
    cin >> x >> y;
    hor[x].insert(y);
    ver[y].insert(x);
  }

  map<pair<int, int>, int> dist;
  dist[{sx, sy}] = 0;

  queue<pair<int, int>> qu;
  qu.push({sx, sy});

  auto add = [&](int x, int y, int d) {
    if (dist.find({x, y}) == dist.end()) {
      dist[{x, y}] = d;
      qu.push({x, y});
    }
  };

  while (!qu.empty()) {
    auto [x, y] = qu.front();
    deb(x, y);
    qu.pop();

    int d = dist[{x, y}];

    if (x == gx && y == gy) {
      cout << dist[{x, y}] << '\n';
      return 0;
    }

    // 横
    auto yy = hor[x].lower_bound(y);
    if (yy != hor[x].end()) { add(x, *yy - 1, d + 1); }
    if (yy != hor[x].begin()) { add(x, *prev(yy) + 1, d + 1); }

    // 縦
    auto xx = ver[y].lower_bound(x);
    if (xx != ver[y].end()) { add(*xx - 1, y, d + 1); }
    if (xx != ver[y].begin()) { add(*prev(xx) + 1, y, d + 1); }
  }

  cout << "-1\n";
}

/*-----------------------------------------------------------
-----------------------------------------------------------*/

#else // INCLUDED_MAIN

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