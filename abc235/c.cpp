#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)v.size()

int main() {
  ll n, q;
  cin >> n >> q;
  map<pair<ll, ll>, int> mp; // mp[{a, b}] := aがb回目に登場するときの要素番号
  map<ll, int> cnt;
  for (int i = 0; i < n; i++) {
    ll a;
    cin >> a;
    cnt[a]++;
    mp[{a, cnt[a]}] = i + 1;
  }
  while (q--) {
    ll x, k;
    cin >> x >> k;
    int ans = mp[{x, k}];
    if (ans == 0)
      cout << -1 << endl;
    else
      cout << ans << endl;
  }
}