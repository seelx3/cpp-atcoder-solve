#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)v.size()

const ll MOD = 998244353;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  // i = 1 ~ N
  // dp[i1][i2][i3] :
  // i1まで見たとき、i2個選んだ総和をiで割った余りがi3となる個数 ans =
  // dp[N][i][0]

  ll ans = 0;

  for (int i = 1; i <= n; i++) {
    vector<vector<vector<ll>>> dp(
        n + 1, vector<vector<ll>>(i + 5, vector<ll>(i + 5, 0)));
    dp[0][0][0] = 1;
    for (int i1 = 0; i1 < n; i1++) {    // a[i1]まで見たとき
      for (int i2 = 0; i2 <= i; i2++) { // i2個選択するとき
        for (int i3 = 0; i3 < i; i3++) {
          // 配るdp
          // dp[i1 + 1][i2][i3] += dp[i1][i2][i3]
          // dp[i1 + 1][i2 + 1][(i3 + a[i1]) % i] += dp[i1][i2][i3]
          dp[i1 + 1][i2][i3] = (dp[i1 + 1][i2][i3] + dp[i1][i2][i3]) % MOD;
          dp[i1 + 1][i2 + 1][(i3 + a[i1]) % i] =
              (dp[i1 + 1][i2 + 1][(i3 + a[i1]) % i] + dp[i1][i2][i3]) % MOD;
        }
      }
    }
    ans = (ans + dp[n][i][0]) % MOD;
  }

  cout << ans << endl;
}