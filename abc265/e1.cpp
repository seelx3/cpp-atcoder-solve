#include <atcoder/all>
#include <bits/stdc++.h>
using namespace atcoder;
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)(v.size())

using P = pair<ll, ll>;
using mint = modint998244353;

int main() {
  ll n, m;
  cin >> n >> m;
  vector<P> dxy(3);
  for (int i = 0; i < 3; i++) {
    cin >> dxy[i].first >> dxy[i].second;
  }
  set<P> obst;
  for (int i = 0; i < m; i++) {
    ll x, y;
    cin >> x >> y;
    obst.insert({x, y});
  }

  // dp[i][j][k]:=
  // i回ワープさせたとき、xをj回、yをk回(、zをi-j-k回)つかったときの移動経路
  vector<vector<vector<mint>>> dp(
      n + 1, vector<vector<mint>>(n + 1, vector<mint>(n + 1)));
  dp[0][0][0] = 1;
  mint ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int x = 0; x <= n; x++) {
      for (int y = 0; y <= n - x; y++) {
        int z = i - x - y;
        auto x_pos = dxy[0].first * x + dxy[1].first * y + dxy[2].first * z;
        auto y_pos = dxy[0].second * x + dxy[1].second * y + dxy[2].second * z;
        if (obst.find({x_pos, y_pos}) != obst.end())
          continue;
        if (z < 0)
          continue;
#ifdef DEBUG
        cout << x << " " << y << " " << z << endl;
#endif
        // dp[i][x][y][z]
        //   += dp[i-1][x-1][y][z] + dp[i-1][x][y-1][z] + dp[i-1][x][y][z-1]
        if (x > 0)
          dp[i][x][y] += dp[i - 1][x - 1][y];
        if (y > 0)
          dp[i][x][y] += dp[i - 1][x][y - 1];
        if (z > 0)
          dp[i][x][y] += dp[i - 1][x][y];
        if (i == n)
          ans += dp[i][x][y];
      }
    }
  }

  cout << ans.val() << endl;
}