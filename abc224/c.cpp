#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)(v.size())

int main() {
  ll n;
  cin >> n;
  vector<pair<ll, ll>> p(n);
  for (ll i = 0; i < n; i++) {
    cin >> p[i].first >> p[i].second;
  }

  sort(ALL(p));

  ll ans = 0;
  for (ll i = 0; i < n - 2; i++) {
    for (ll j = i + 1; j < n - 1; j++) {
      for (ll k = j + 1; k < n; k++) {
        ll dx1 = p[j].first - p[i].first;
        ll dy1 = p[j].second - p[i].second;
        ll dx2 = p[k].first - p[i].first;
        ll dy2 = p[k].second - p[i].second;
        if (dy1 * dx2 != dy2 * dx1)
          ans++;
      }
    }
  }

  cout << ans << endl;
}