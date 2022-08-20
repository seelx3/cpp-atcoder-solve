#include <atcoder/all>
#include <bits/stdc++.h>
using namespace atcoder;
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)(v.size())

using mint = modint998244353;

int main() {
  ll n, m, K;
  cin >> n >> m >> K;

  vector<fenwick_tree<mint>> dp(n, fenwick_tree<mint>(m));
  for (int j = 0; j < m; j++) {
    dp[0].add(j, 1);
  }
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < m; j++) {
      // j-K+1 ~ j+K-1
      int l = max(0LL, j - K + 1), r = min(j + K - 1, m - 1);
      if (K == 0)
        r = l - 1;
      dp[i].add(j, dp[i - 1].sum(0, m) - dp[i - 1].sum(l, r + 1));
    }
  }
  cout << dp[n - 1].sum(0, m).val() << endl;
}