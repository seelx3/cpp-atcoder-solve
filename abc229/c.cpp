#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)(v.size())

int main() {
  ll n, w;
  cin >> n >> w;
  vector<pair<ll, ll>> p(n);
  for (int i = 0; i < n; i++) {
    ll a, b;
    cin >> a >> b;
    p[i] = {a, b};
  }
  sort(ALL(p), greater<>());
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    if (p[i].second <= w) {
      ans += p[i].first * p[i].second;
      w -= p[i].second;
    } else {
      ans += p[i].first * w;
      break;
    }
  }
  cout << ans << endl;
}