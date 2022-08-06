#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)v.size()

int main() {
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }

  vector<vector<bool>> dp(n + 5, vector<bool>(2));
  dp[0][0] = true;
  dp[0][1] = true;

  bool ans = true;
  for (int i = 1; i < n; i++) {
    if (dp[i - 1][0] && abs(a[i - 1] - a[i]) <= k)
      dp[i][0] = true;
    if (dp[i - 1][1] && abs(b[i - 1] - a[i]) <= k)
      dp[i][0] = true;
    if (dp[i - 1][0] && abs(a[i - 1] - b[i]) <= k)
      dp[i][1] = true;
    if (dp[i - 1][1] && abs(b[i - 1] - b[i]) <= k)
      dp[i][1] = true;
    if (!dp[i][0] && !dp[i][1])
      ans = false;
  }

  if (ans)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}