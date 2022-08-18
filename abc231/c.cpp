#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)(v.size())

const ll inf = LONG_LONG_MAX;

int main() {
  ll n, q;
  cin >> n >> q;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  a.push_back(inf);
  sort(ALL(a));

  while (q--) {
    ll x;
    cin >> x;
    cout << n - (lower_bound(ALL(a), x) - a.begin()) << endl;
  }
}