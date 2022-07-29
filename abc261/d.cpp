#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)v.size()

int main() {
  ll n, m;
  cin >> n >> m;
  vector<ll> x(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> x[i + 1];
  }
  vector<ll> c(n + 1);
  for (int i = 0; i < m; i++) {
    ll a, b;
    cin >> a >> b;
    c[a] = b;
  }

  vector<vector<ll>> dp(n + 1, vector<ll>(n + 1));
  // dp[i][j]: i回目終了後に連続j回表であるときのgain
  // i > 0, dp[i][j] = x[i] + dp[i-1][j-1] + c[j];
  // i ==0, dp[i][0] = max(dp[i-1][j])
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= i; j++) {
      if (j == 0) {
        for (int k = 0; k < n; k++) {
          dp[i][0] = max(dp[i][0], dp[i - 1][k]);
        }
      } else {
        dp[i][j] = x[i] + dp[i - 1][j - 1] + c[j];
      }
    }
  }
  ll ans = 0;
  for (int i = 0; i <= n; i++) {
    ans = max(ans, dp[n][i]);
  }
  cout << ans << endl;
}