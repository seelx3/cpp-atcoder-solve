#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)v.size()

const ll MOD = 998244353;

int main() {
  ll n, m, k;
  cin >> n >> m >> k;
  vector<vector<ll>> dp(n + 1, vector<ll>(k + 1));
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= k; j++) {
      for (int l = 1; l <= m; l++) {
        if (j - l >= 0)
          dp[i][j] = (dp[i][j] + dp[i - 1][j - l]) % MOD;
      }
    }
  }
  ll ans = 0;
  for (int i = 0; i <= k; i++) {
    ans = (ans + dp[n][i]) % MOD;
  }
  cout << ans << endl;
}