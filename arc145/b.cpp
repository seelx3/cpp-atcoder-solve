#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)v.size()

int main() {
  ll n, a, b;
  cin >> n >> a >> b;
  if (a <= b) {
    cout << max(0LL, n - (a - 1)) << endl;
  } else {
    ll ans = 0;
    n = max(0LL, n - (a - 1)); // <= ここでmax(0, *)をし忘れててWA...
    ans += b * (n / a);
    n %= a;
    ans += min(n, b);
    cout << ans << endl;
  }
}