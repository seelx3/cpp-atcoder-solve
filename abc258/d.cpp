#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)(v.size())

#define chmin(a, b) a = min(a, b)

const ll inf = LONG_LONG_MAX;

int main() {
  ll n, x;
  cin >> n >> x;
  vector<ll> a(n), b(n), sum(n);

  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    if (i > 0)
      sum[i] += sum[i - 1] + a[i] + b[i];
    else
      sum[i] += a[i] + b[i];
  }

  ll ans = inf;

  for (int i = 0; i < n; i++) {
    // sum[i]: i番目のステージまででi+1回クリア
#ifdef DEBUG
    cout << i << " : " << sum[i] << endl;
#endif
    if (x - (i + 1) >= 0)
      chmin(ans, sum[i] + (x - (i + 1)) * b[i]);
  }

  cout << ans << endl;
}