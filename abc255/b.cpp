#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)v.size()

int main() {
  int n, k;
  cin >> n >> k;
  vector<bool> have_light(n);
  vector<int> a(k);
  for (int i = 0; i < k; i++) {
    cin >> a[i];
    a[i]--;
    have_light[a[i]] = true;
  }
  vector<double> x(n), y(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }

  double ans = 0.0;
  for (int i = 0; i < n; i++) {
    if (have_light[i])
      continue;
    double min_dist = 300000.0;
    for (int j = 0; j < k; j++) {
      double d = (x[i] - x[a[j]]) * (x[i] - x[a[j]]) +
                 (y[i] - y[a[j]]) * (y[i] - y[a[j]]);
      d = sqrt(d);
      min_dist = min(min_dist, d);
    }
    ans = max(ans, min_dist);
  }

  cout << fixed << setprecision(10) << ans << endl;
}