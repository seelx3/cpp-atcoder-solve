#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)(v.size())

int main() {
  ll q;
  cin >> q;
  ll n = (1LL << 20);
  vector<ll> a(n, -1);
  vector<ll> nx(n);
  for (ll i = 0; i < n; i++)
    nx[i] = (i + 1) % n;
  for (ll i = 0; i < q; i++) {
    ll t, x;
    cin >> t >> x;
    if (t == 1) {
      ll h = x % n;
      while (a[h] != -1) {
        h = nx[h];
      }
      if (x % n != h)
        nx[x % n] = h;
      a[h] = x;
    } else {
      cout << a[x % n] << endl;
    }
  }
}