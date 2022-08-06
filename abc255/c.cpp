#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)v.size()

int main() {
  ll x, a, d, n;
  cin >> x >> a >> d >> n;

  if (d < 0) {
    a = a + d * (n - 1);
    d = -d;
  }

  ll s_l = a;
  ll s_r = a + d * (n - 1);
  if (x < s_l) {
    cout << s_l - x << endl;
  } else if (x > s_r) {
    cout << x - s_r << endl;
  } else if (x >= s_l && x <= s_r) {
    if (d == 0) {
      cout << 0 << endl;
    } else {
      ll ans = (x - s_l) % d;
      cout << min(ans, d - ans) << endl;
    }
  }
}