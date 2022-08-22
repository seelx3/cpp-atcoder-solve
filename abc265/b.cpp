#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)(v.size())

int main() {
  ll n, m, t;
  cin >> n >> m >> t;
  vector<ll> a(n - 1);
  for (int i = 0; i < n - 1; i++) {
    cin >> a[i];
  }
  vector<ll> add(n);
  for (int i = 0; i < m; i++) {
    ll x, y;
    cin >> x >> y;
    x--;
    add[x] = y;
  }
  ll now = t;
  for (int i = 0; i < n - 1; i++) {
    now += add[i];
    if (now <= a[i]) {
      cout << "No" << endl;
      return 0;
    }
    now -= a[i];
  }
  cout << "Yes" << endl;
}