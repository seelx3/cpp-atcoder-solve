#include <atcoder/all>
#include <bits/stdc++.h>
using namespace atcoder;
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)(v.size())

using mint = modint998244353;

int main() {
  ll n, m, k;
  cin >> n >> m >> k;

  vector<vector<mint>> dp(n, vector<mint>(m)), sum(n, vector<mint>(m)),
      sumr(n, vector<mint>(m));

  for (int j = 0; j < m; j++) {
    dp[0][j] = 1;
    if (j == 0)
      sum[0][j] = dp[0][j];
    else
      sum[0][j] += sum[0][j - 1] + dp[0][j];
  }
  for (int j = m - 1; j >= 0; j--) {
    if (j == m - 1)
      sumr[0][j] = dp[0][j];
    else
      sumr[0][j] += sumr[0][j + 1] + dp[0][j];
  }

  for (int i = 1; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (k == 0) {
        dp[i][j] = sum[i - 1][m - 1];
      } else {
        int l = j - k;
        int r = j + k;
        if (l >= 0)
          dp[i][j] += sum[i - 1][l];
        if (r <= m - 1)
          dp[i][j] += sumr[i - 1][r];
      }
      if (j == 0) {
        sum[i][j] = dp[i][j];
      } else {
        sum[i][j] += sum[i][j - 1] + dp[i][j];
      }
    }
    for (int j = m - 1; j >= 0; j--) {
      if (j == m - 1) {
        sumr[i][j] = dp[i][j];
      } else {
        sumr[i][j] += sumr[i][j + 1] + dp[i][j];
      }
    }
  }

#ifdef DEBUG
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << dp[i][j].val() << " \n"[j == m - 1];
    }
  }
  cout << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << sum[i][j].val() << " \n"[j == m - 1];
    }
  }
#endif

  cout << sum[n - 1][m - 1].val() << endl;
}