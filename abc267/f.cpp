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

int main() {
  ll N = input();
  Graph G(N);
  REP(i, N - 1) {
    int a = (int)input() - 1;
    int b = (int)input() - 1;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  int Q = input();
  vector<pair<int, int>> qs(Q);
  vector<vector<int>> frqs(N);
  REP(i, Q) {
    cin >> qs[i].first >> qs[i].second;
    qs[i].first--;
    frqs[qs[i].first].push_back(qs[i].second);
  }

  auto getroot = [&](int s) -> int {
    vector<int> dist(N, -1);
    dist[s] = 0;
    queue<int> qu;
    int ret = s;
    qu.push(s);
    while (!qu.empty()) {
      // deb(qu);
      int u = qu.front();
      qu.pop();
      for (auto v : G[u]) {
        if (dist[v] != -1) continue;
        dist[v] = dist[u] + 1;
        if (dist[ret] < dist[v]) ret = v;
        qu.push(v);
      }
    }
    return ret; // sを根としたとき最も深い位置にある頂点
  };

  int rt1 = getroot(0);
  int rt2 = getroot(rt1);

  deb(rt1, rt2);

  map<pair<int, int>, int> ans;

  auto getqans = [&](int s) -> void {
    vector<bool> seen(N);
    deque<int> dq;
    function<void(int)> dfs = [&](int u) -> void {
      seen[u] = true;
      dq.push_back(u);
      deb(dq);
      for (auto k : frqs[u]) {
        if (SZ(dq) - 1 - k < 0) continue;
        ans[{u, k}] = dq[SZ(dq) - 1 - k];
      }
      for (auto v : G[u]) {
        if (!seen[v]) dfs(v);
      }
      dq.pop_back();
    };
    dfs(s);
  };

  getqans(rt1);
  getqans(rt2);

  REP(i, Q) {
    auto [u, k] = qs[i];
    if (ans.find({u, k}) == ans.end()) {
      cout << -1 << endl;
    } else {
      cout << ans[{u, k}] + 1 << endl;
    }
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

template <class T> vector<T> make_vec(size_t a, T init) { return vector<T>(a, init); }
template <class T, class... Ts> auto make_vec(size_t a, Ts... ts) {
  return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
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