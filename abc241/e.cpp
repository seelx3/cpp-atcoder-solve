#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)v.size()

int main() {
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  vector<ll> sum(n);
  vector<ll> seen(n, -1);
  seen[0] = 0;
  ll s1, s2;

  for (int i = 0; i < n; i++) {
    sum[i + 1] = sum[i] + a[sum[i] % n];
    if (seen[sum[i + 1] % n] != -1) {
      s1 = seen[sum[i + 1] % n];
      s2 = i + 1;
      break;
    }
    seen[sum[i + 1] % n] = i + 1;
  }

  // cout << "s1 = " << s1 << endl;
  // cout << "s2 = " << s2 << endl;

  if (k <= s1) {
    cout << sum[k] << endl;
  } else {
    ll lp_sz = s2 - s1;
    ll lp_gain = sum[s2] - sum[s1];
    ll lp_cnt = (k - s1) / lp_sz;
    ll rest = (k - s1) % lp_sz;
    // cout << "lp_cnt = " << lp_cnt << endl;
    // cout << "rest = " << rest << endl;
    cout << sum[s1 + rest] + lp_cnt * lp_gain << endl;
  }
}