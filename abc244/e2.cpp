#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(),v.end()
#define sz(v) (int)v.size()

#define vl vector<ll>
#define vvl vector<vl>
const ll MOD = 998244353;

int main(){
  int n, m, k, s, t, x;
  cin >> n >> m >> k >> s >> t >> x;
  s--; t--; x--;
  vector<vector<int>> G(n);
  for(int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--; v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  
  vector<vvl> dp(k+1, vector<vl>(n, vector<ll>(2, 0)));
  // ステップ 頂点 Xを通った回数の偶奇 
  dp[0][s][0] = 1; 

  for(int i = 0; i < k; i++) {
    for(int v = 0; v < n; v++) {
      for(auto u : G[v]) {
        if(v == x) {
          dp[i+1][u][0] = (dp[i+1][u][0] + dp[i][v][1]) % MOD;
          dp[i+1][u][1] = (dp[i+1][u][1] + dp[i][v][0]) % MOD;
        } else {
          dp[i+1][u][0] = (dp[i+1][u][0] + dp[i][v][0]) % MOD;
          dp[i+1][u][1] = (dp[i+1][u][1] + dp[i][v][1]) % MOD;
        }
      }
    }
  }

  cout << dp[k][t][0] << endl;
}