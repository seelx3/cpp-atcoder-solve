#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)v.size()

#define chmin(a, b) a = min(a, b)

const ll inf = LONG_LONG_MAX;

int main() {
  ll n, l, r;
  cin >> n >> l >> r;
  vector<ll> a(n), rev_a;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  rev_a = a;
  reverse(ALL(rev_a));

  vector<ll> f(n + 1), g(n + 1);

  // f[i] := x<=iのときのa[j](0<=j<i)の総和の最小値
  // f[1] = min(f[0]+a[0], l * 1);

  for (int i = 1; i <= n; i++) {
    f[i] = min(l * i, f[i - 1] + a[i - 1]);
    g[i] = min(r * i, g[i - 1] + rev_a[i - 1]);
  }
  ll ans = inf;
  for (int i = 0; i <= n; i++) {
    chmin(ans, f[i] + g[n - i]);
  }
  cout << ans << endl;

#ifdef DEBUG
  for (int i = 0; i <= n; i++) {
    cout << f[i] << " \n"[i == n];
  }
  for (int i = n; i >= 0; i--) {
    cout << g[i] << " \n"[i == 0];
  }
#endif
}