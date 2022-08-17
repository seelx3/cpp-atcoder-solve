#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)(v.size())

#define ALPHABET_CNT 26

const int MAX = 10000;
const ll MOD = 998244353;

long long fac[MAX], finv[MAX], inv[MAX];

void COMinit() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < MAX; i++) {
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
}

long long COM(int n, int k) {
  if (n < k)
    return 0;
  if (n < 0 || k < 0)
    return 0;
  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main() {
  COMinit();

  string s;
  cin >> s;
  ll n = sz(s);

  vector<ll> cnt(ALPHABET_CNT + 1);
  for (int i = 0; i < n; i++) {
    cnt[s[i] - 'a' + 1]++;
  }

  vector<vector<ll>> dp(ALPHABET_CNT + 1, vector<ll>(n + 1));
  for (int i = 0; i <= ALPHABET_CNT; i++)
    dp[i][0] = 1;

  for (int i = 1; i <= ALPHABET_CNT; i++) {
    for (int j = 1; j <= n; j++) {
      for (int k = 0; k <= cnt[i]; k++) {
        // dp[i][j] += dp[i-1][j-k] * (j! / ((j-k)!k!))
        if (j - k < 0)
          break;
        dp[i][j] += dp[i - 1][j - k] * COM(j, k);
        dp[i][j] %= MOD;
      }
    }
  }

  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += dp[ALPHABET_CNT][i];
    ans %= MOD;
  }

  cout << ans << endl;

#ifdef DEBUG
  for (int i = 1; i <= 2; i++) {
    cout << "i: " << i << ", ";
    for (int j = 1; j <= n; j++) {
      cout << dp[i][j] << " \n"[j == n];
    }
  }
#endif
}