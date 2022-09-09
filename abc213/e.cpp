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
  int H, W;
  cin >> H >> W;
  vector<string> S = input(H);

  vector<vector<int>> dist = make_vec(H, W, -1);

  deque<pair<int, pair<int, int>>> dq;
  dq.push_back({0, {0, 0}});

  while (!dq.empty()) {
    auto [d, cur] = dq.front();
    dq.pop_front();

    if (dist[cur.first][cur.second] != -1) continue;
    dist[cur.first][cur.second] = d;
    REP(i, -2, 2 + 1) {   // -2 ~ 2
      REP(j, -2, 2 + 1) { // -2 ~ 2
        if ((i == -2 && j == -2) || (i == -2 && j == 2) ||
            (i == 2 && j == -2) || (i == 2 && j == 2)) {
          continue;
        }
        int nx = cur.first + i;
        int ny = cur.second + j;
        if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
        if (dist[nx][ny] != -1) continue;
        if (((i == 0 && j == 1) || (i == 0 && j == -1) || (i == 1 && j == 0) ||
             (i == -1 && j == 0)) &&
            S[nx][ny] == '.') {
          dq.push_front({d, {nx, ny}});
        } else {
          dq.push_back({d + 1, {nx, ny}});
        }
      }
    }
  }

  deb(dist);

  cout << dist[H - 1][W - 1] << endl;
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