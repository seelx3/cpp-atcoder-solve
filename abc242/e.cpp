#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)v.size()

const ll MOD = 998244353;

int main() {
  int t;
  cin >> t;

  int maxn = 1001001;
  vector<ll> pow24(maxn);
  pow24[1] = 1;
  for (int i = 2; i < maxn; i++) {
    pow24[i] = (26LL * pow24[i - 1]) % MOD;
  }

  while (t--) {
    ll n;
    string s;
    cin >> n >> s;
    ll ans = 0;
    for (int i = 0; i < (n + 1) / 2; i++) {
      ans += (ll)(s[i] - 'A') * pow24[(n - i * 2 + 1) / 2];
      ans %= MOD;
#ifdef DEBUG
      cout << i << " : " << ans << endl;
      cout << (n - i * 2 + 1) / 2 << endl;
#endif
    }
    string ss = s;
    for (int i = 0; i < n / 2; i++) {
      ss[n - 1 - i] = ss[i];
    }
    if (ss <= s)
      ans = (ans + 1) % MOD;
    cout << ans << endl;
  }
}