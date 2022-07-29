#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)v.size()

int main() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(ALL(a));
  a.push_back(500500);
  ll ans = 0;
  for (int i = 1; i < n - 1; i++) {
    // ans += a[i]より小さい値の個数* a[i]より大きい値の個数
    ll le = lower_bound(ALL(a), a[i]) - a.begin();
    ll ri = a.end() - lower_bound(ALL(a), a[i] + 1) - 1;
    // cout << "i = " << i << " : ";
    // cout << "le = " << le << " ri = " << ri << endl;
    ans += le * ri;
  }
  cout << ans << endl;
}