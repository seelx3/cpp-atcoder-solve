#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)(v.size())

int main() {
  int n;
  cin >> n;
  double ans = 0.0;
  double r = 1.0;
  for (int i = 1; i <= n; i++) {
    if (i < n - 4) {
      ans += r * (1.0 / 6.0) * 6.0;
      r *= (5.0 / 6.0);
    } else if (i < n - 1) {
      ans += r * (2.0 / 6.0) * 5.5;
      r *= (4.0 / 6.0);
    } else if (i == n - 1) {
      ans += r * (3.0 / 6.0) * 5.0;
      r *= (3.0 / 6.0);
    } else if (i == n) {
      ans += r * 3.5;
    }
  }

  cout << fixed << setprecision(10) << ans << endl;
}