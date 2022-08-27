#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)(v.size())

int main() {
  ll n;
  cin >> n;

  map<ll, pair<ll, ll>> mp;
  for (int i = 0; i < n; i++) {
    ll t, x, a;
    cin >> t >> x >> a;
    mp[t] = {x + 1, a};
  }

  vector<vector<ll>> dp(100100, vector<ll>(7, -1));
  dp[0][1] = 0;

  for (int i = 1; i <= 100000; i++) {
    if (mp.find(i) == mp.end()) {
      for (int j = 1; j <= 5; j++)
        for (int k = -1; k <= 1; k++) {
          if (dp[i - 1][j + k] == -1)
            continue;
          dp[i][j] = max(dp[i][j], dp[i - 1][j + k]);
        }
    } else {
      for (int j = 1; j <= 5; j++) {
        bool ok = false;
        for (int k = -1; k <= 1; k++) {
          if (dp[i - 1][j + k] == -1)
            continue;
          ok = true;
          dp[i][j] = max(dp[i][j], dp[i - 1][j + k]);
        }
        if (ok && j == mp[i].first)
          dp[i][j] += mp[i].second;
      }
    }
  }

  ll ans = 0;
  for (int i = 1; i <= 5; i++) {
    ans = max(ans, dp[100000][i]);
  }

  cout << ans << endl;
}