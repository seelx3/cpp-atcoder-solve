#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)(v.size())

int main() {
  ll n;
  cin >> n;
  vector<vector<ll>> a(n);
  vector<ll> t(n);
  for (ll i = 0; i < n; i++) {
    cin >> t[i];
    ll k;
    cin >> k;
    for (ll j = 0; j < k; j++) {
      ll x;
      cin >> x;
      x--;
      a[i].push_back(x);
    }
  }

  vector<bool> b(n, false);
  function<ll(ll)> rec = [&](ll x) {
    ll sub = 0;
    for (ll i = 0; i < sz(a[x]); i++) {
      if (!b[a[x][i]]) {
        sub += rec(a[x][i]);
      }
    }
    sub += t[x];
    b[x] = true;
    return sub;
  };
  cout << rec(n - 1) << endl;
}