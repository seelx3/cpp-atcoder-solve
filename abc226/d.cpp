#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)(v.size())

int main() {
  ll n;
  cin >> n;
  vector<ll> x(n), y(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }
  set<pair<ll, ll>> snuke_magic;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (j == i)
        continue;
      ll dx = x[j] - x[i];
      ll dy = y[j] - y[i];
      if (dx == 0) {
        snuke_magic.insert({0, dy / abs(dy)});
      } else if (dy == 0) {
        snuke_magic.insert({dx / abs(dx), 0});
      } else {
        ll k = gcd(dx, dy);
        snuke_magic.insert({dx / k, dy / k});
      }
    }
  }

  cout << sz(snuke_magic) << endl;
}