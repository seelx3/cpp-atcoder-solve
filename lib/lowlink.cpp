#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)(v.size())

// 関節点、橋
// 関節点：とり除いたときに、グラフが非連結となるような頂点
// 橋：とり除いたときに、グラフが非連結となるような辺

// ライブラリ引用元
// グラフにおける橋(bridge)を検出するアルゴリズム
// https://algo-logic.info/bridge-lowlink/

// 例題：https://onlinejudge.u-aizu.ac.jp/problems/GRL_3_A

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
  int V, E;
  cin >> V >> E;
  Graph G(V);
  for (int i = 0; i < E; i++) {
    int u, v;
    cin >> u >> v;
    G[u].push_back({v});
    G[v].push_back({u});
  }
  LowLink LowL(G);
  for (auto v : LowL.aps) {
    cout << v << endl;
  }
}