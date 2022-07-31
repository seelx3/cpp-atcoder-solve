#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)v.size()

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<bool>> G(104, vector<bool>(104));
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    G[u][v] = true;
    G[v][u] = true;
  }
  ll ans = 0;
  for (int i = 0; i < n - 2; i++) {
    for (int j = i + 1; j < n - 1; j++) {
      for (int k = j + 1; k < n; k++) {
        if (G[i][j] && G[j][k] && G[k][i])
          ans++;
      }
    }
  }
  cout << ans << endl;
}