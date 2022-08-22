#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)(v.size())

const ll inf = LONG_LONG_MAX;

int main() {
  ll n, p, q, r;
  cin >> n >> p >> q >> r;
  vector<ll> a(n + 1), sum(n + 2);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (i == 1) {
      sum[i] = a[i];
    } else {
      sum[i] += sum[i - 1] + a[i];
    }
  }
  sum[n + 1] = inf;

#ifdef DEBUG
  for (int i = 0; i < n + 2; i++) {
    cout << sum[i] << " \n"[i == n + 1];
  }
#endif

  bool ok = false;
  for (int x = 0; x < n; x++) {
    int y = lower_bound(ALL(sum), sum[x] + p) - sum.begin();
    if (sum[y] - sum[x] != p)
      continue;
    int z = lower_bound(ALL(sum), sum[y] + q) - sum.begin();
    if (sum[z] - sum[y] != q)
      continue;
    int w = lower_bound(ALL(sum), sum[z] + r) - sum.begin();
    if (sum[w] - sum[z] != r)
      continue;
    ok = true;
  }

  if (ok)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}