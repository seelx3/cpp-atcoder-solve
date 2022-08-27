#include <atcoder/all>
#include <bits/stdc++.h>
using namespace atcoder;
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)v.size()

struct Edge {
  int to;
};
using Graph = vector<vector<Edge>>;
using P = pair<long, long>;

struct LowLink {
  const Graph& G;
  vector<int> used, ord, low;
  vector<int> aps;
  vector<P> bridges;

  LowLink(const Graph& G_) : G(G_) {
    used.assign(G.size(), 0);
    ord.assign(G.size(), 0);
    low.assign(G.size(), 0);
    int k = 0;
    for (int i = 0; i < (int)G.size(); i++) {
      if (!used[i])
        k = dfs(i, k, -1);
    }
    sort(aps.begin(), aps.end());
    sort(bridges.begin(), bridges.end());
  }

  int dfs(int id, int k, int par) {
    used[id] = true;
    ord[id] = k++;
    low[id] = ord[id];
    bool is_aps = false;
    int count = 0;
    for (auto& e : G[id]) {
      if (!used[e.to]) {
        count++;
        k = dfs(e.to, k, id);
        low[id] = min(low[id], low[e.to]);
        if (par != -1 && ord[id] <= low[e.to])
          is_aps = true;
        if (ord[id] < low[e.to])
          bridges.emplace_back(min(id, e.to), max(id, e.to));
      } else if (e.to != par) {
        low[id] = min(low[id], ord[e.to]);
      }
    }
    if (par == -1 && count >= 2)
      is_aps = true;
    if (is_aps)
      aps.push_back(id);
    return k;
  }
};

int main() {
  int n;
  cin >> n;
  Graph G(n);
  vector<pair<int, int>> edg(n);
  for (int i = 0; i < n; i++) {
    cin >> edg[i].first >> edg[i].second;
    edg[i].first--;
    edg[i].second--;
    if (edg[i].first > edg[i].second)
      swap(edg[i].first, edg[i].second);
    G[edg[i].first].push_back({edg[i].second});
    G[edg[i].second].push_back({edg[i].first});
  }
  LowLink lowlink(G);
  set<pair<int, int>> brdg;
  for (auto [u, v] : lowlink.bridges) {
    // cout << u << " " << v << endl;
    brdg.insert({u, v});
  }
  dsu uf(n);
  for (auto [u, v] : edg) {
    if (brdg.count({u, v})) {
      uf.merge(u, v);
    }
  }

  int q;
  cin >> q;
  while (q--) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    cout << (uf.same(u, v) ? "Yes" : "No") << endl;
  }
}