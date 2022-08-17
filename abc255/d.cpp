#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)(v.size())

const ll inf = LONG_LONG_MAX;

int main() {
  ll n, q;
  cin >> n >> q;
  vector<ll> a(n), sum(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(ALL(a));
  for (int i = 0; i < n; i++) {
    if (i > 0)
      sum[i] += sum[i - 1] + a[i];
    else
      sum[i] += a[i];
  }
  a.push_back(inf);

  for (int i = 0; i < q; i++) {
    ll x;
    cin >> x;
    int r = lower_bound(ALL(a), x) - a.begin();
    // 2 / 5, 5, 6, 11
    // 3 / 0, 0, 1,  6
    if (r == 0) {
      cout << sum[n - 1] - x * n << endl;
    } else if (r == n) {
      cout << x * n - sum[n - 1] << endl;
    } else {
#ifdef DEBUG
      cout << "debug" << endl;
      cout << "r = " << r << endl;
      cout << (x * r - sum[r - 1]) << endl;
      cout << (sum[n - 1] - sum[r - 1] - x * (n - r)) << endl;
      cout << "end deb" << endl;
#endif
      cout << (x * r - sum[r - 1]) + (sum[n - 1] - sum[r - 1] - x * (n - r))
           << endl;
    }
  }
}