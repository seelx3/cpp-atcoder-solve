#include <atcoder/all>
#include <bits/stdc++.h>
using namespace atcoder;
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)(v.size())

using mint = modint998244353;

int main() {
  ll h, w, k;
  cin >> h >> w >> k;
  ll sx, sy, gx, gy;
  cin >> sx >> sy >> gx >> gy;

  vector<vector<vector<mint>>> dp(k + 1,
                                  vector<vector<mint>>(2, vector<mint>(2)));
  dp[0][0][0] = (sx != gx && sy != gy);
  dp[0][0][1] = (sx != gx && sy == gy);
  dp[0][1][0] = (sx == gx && sy != gy);
  dp[0][1][1] = (sx == gx && sy == gy);

  for (int i = 1; i <= k; i++) {
    dp[i][0][0] += dp[i - 1][0][0] * (h - 2 + w - 2) +
                   dp[i - 1][0][1] * (w - 1) + dp[i - 1][1][0] * (h - 1);
    dp[i][0][1] +=
        dp[i - 1][0][0] + dp[i - 1][0][1] * (h - 2) + dp[i - 1][1][1] * (h - 1);
    dp[i][1][0] +=
        dp[i - 1][0][0] + dp[i - 1][1][0] * (w - 2) + dp[i - 1][1][1] * (w - 1);
    dp[i][1][1] += dp[i - 1][0][1] + dp[i - 1][1][0];
  }
#ifdef DEBUG
  for (int i = 0; i <= k; i++) {
    cout << dp[i][0][0].val() << " " << dp[i][0][1].val() << " "
         << dp[i][1][0].val() << " " << dp[i][1][1].val() << endl;
  }
#endif

  cout << dp[k][1][1].val() << endl;
}