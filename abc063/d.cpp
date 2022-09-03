#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)(v.size())

int main() {
  ll n, a, b;
  cin >> n >> a >> b;
  ll d = a - b;

  vector<ll> h(n);
  for (int i = 0; i < n; i++) {
    cin >> h[i];
  }
  ll l = 0;
  ll r = 1000000001;

  vector<ll> h_tmp(n);
  auto ok = [&](ll x) -> bool {
    for (int i = 0; i < n; i++) {
      h_tmp[i] = max(h[i] - x * b, 0LL);
    }
    ll y = 0;
    for (int i = 0; i < n; i++) {
      y += (h_tmp[i] + d - 1) / d;
    }
    return (y <= x);
  };

  while (l + 1 < r) {
    ll m = (l + r) / 2;
    // m 回ですべてのまものを消し去ることができる
    if (ok(m))
      r = m;
    else
      l = m;
  }

  cout << r << endl;
}