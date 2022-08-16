#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)v.size()

template <typename T> struct edge {
  int src, to;
  T cost;

  edge(int to, T cost) : src(-1), to(to), cost(cost) {}

  edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}

  edge& operator=(const int& x) {
    to = x;
    return *this;
  }

  operator int() const { return to; }
};

template <typename T> using Edges = vector<edge<T>>;
using UnWeightedGraph = vector<vector<int>>;

template <typename G> struct StronglyConnectedComponents {
  const G& g;
  UnWeightedGraph gg, rg;
  vector<int> comp, order, used;

  StronglyConnectedComponents(G& g)
      : g(g), gg(g.size()), rg(g.size()), comp(g.size(), -1), used(g.size()) {
    for (int i = 0; i < g.size(); i++) {
      for (auto e : g[i]) {
        gg[i].emplace_back((int)e);
        rg[(int)e].emplace_back(i);
      }
    }
  }

  int operator[](int k) { return comp[k]; }

  void dfs(int idx) {
    if (used[idx])
      return;
    used[idx] = true;
    for (int to : gg[idx])
      dfs(to);
    order.push_back(idx);
  }

  void rdfs(int idx, int cnt) {
    if (comp[idx] != -1)
      return;
    comp[idx] = cnt;
    for (int to : rg[idx])
      rdfs(to, cnt);
  }

  void build(UnWeightedGraph& t) {
    for (int i = 0; i < gg.size(); i++)
      dfs(i);
    reverse(begin(order), end(order));
    int ptr = 0;
    for (int i : order)
      if (comp[i] == -1)
        rdfs(i, ptr), ptr++;

    t.resize(ptr);
    for (int i = 0; i < g.size(); i++) {
      for (auto& to : g[i]) {
        int x = comp[i], y = comp[to];
        if (x == y)
          continue;
        t[x].push_back(y);
      }
    }
  }
};
