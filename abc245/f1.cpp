#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)(v.size())

using Graph = vector<vector<int>>;

int main() {
  int n, m;
  cin >> n >> m;
  Graph rev_g(n);
  scc_graph g(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    g.add_edge(u, v);
    rev_g[v].push_back(u);
  }
  auto scc = g.scc();
  int k = sz(scc);

  vector<int> id(n);
  for (int i = 0; i < k; i++) {
    for (auto v : scc[i]) {
      id[v] = i;
    }
  }

  vector<bool> seen(n);
  int ans = 0;
  function<void(int)> dfs = [&](int u) -> void {
    for (auto v : rev_g[u]) {
      if (seen[v])
        continue;
      seen[v] = true;
      ans++;
      dfs(v);
    }
  };

  for (int v = 0; v < n; v++) {
    if (seen[v] || sz(scc[id[v]]) < 2)
      continue;
    dfs(v);
  }

  cout << ans << endl;
}