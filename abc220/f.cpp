#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)(v.size())

using Graph = vector<vector<int>>;

int main() {
  ll n;
  cin >> n;
  Graph G(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  // root を 0 としてdfs
  vector<ll> ans(n);
  vector<int> par(n);      // parent
  vector<ll> sub_sz(n, 1); // sub_sz[i] = size of sub_tree which root is i

  function<ll(int, int, int, bool)> dfs = [&](int u, int p, int d,
                                              bool getans) -> ll {
    if (getans && u != 0) {
      ans[u] = ans[p] + n - 2 * sub_sz[u];
#ifdef DEBUG
      cout << "ans[" << u << "] = " << ans[p] << " * " << n << " - 2 * "
           << sub_sz[u] << endl;
#endif
    }
    for (auto v : G[u]) {
      if (v == p)
        continue;
      if (!getans) {
        sub_sz[u] += dfs(v, u, d + 1, false);
      } else {
        dfs(v, u, d + 1, true);
      }
    }
    if (!getans) {
      ans[0] += d;
    }
    return sub_sz[u];
  };

  dfs(0, 0, 0, false); // sub_sz 構築
  dfs(0, 0, 0, true);  // ans もとめる
#ifdef DEBUG
  for (int i = 0; i < n; i++) {
    cout << i << " : " << sub_sz[i] << endl;
  }
#endif
  for (int i = 0; i < n; i++) {
    cout << ans[i] << endl;
  }
}