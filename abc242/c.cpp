#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)v.size()

const ll MOD = 998244353;

int main() {
  ll n;
  cin >> n;
  vector<vector<ll>> dp(n, vector<ll>(10));
  for (int j = 1; j <= 9; j++) {
    dp[0][j] = 1;
  }
  for (int i = 1; i < n; i++) {
    for (int j = 1; j <= 9; j++) {
      if (j >= 2)
        dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
      dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
      if (j <= 8)
        dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % MOD;
    }
  }
  ll ans = 0;
  for (int j = 1; j <= 9; j++) {
    ans = (ans + dp[n - 1][j]) % MOD;
  }
  cout << ans << endl;
}