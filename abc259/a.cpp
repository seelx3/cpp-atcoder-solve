#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)v.size()

int main() {
  ll n, m, x, t, d;
  cin >> n >> m >> x >> t >> d;

  ll ans = t;
  for (int i = n; i > m; i--) {
    if (i <= x)
      ans -= d;
  }
  cout << ans << endl;
}