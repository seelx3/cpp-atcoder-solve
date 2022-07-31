#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)v.size()

const ll INF = 100100100100;

int main() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  vector<pair<ll, ll>> vp;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
    vp.push_back({i, a[i]});
  }
  ll same = 0, cnt = 0;
  sort(ALL(vp));
  for (int i = 0; i < n; i++) {
    if (a[i] == i) {
      same++;
    } else {
      auto b = *lower_bound(ALL(vp), make_pair(a[i], -INF));
      // cout << b.first << ", " << b.second << endl;
      if (i == b.second)
        cnt++;
    }
  }

  ll ans = same * (same - 1) / 2;
  ans += cnt / 2;
  cout << ans << endl;
}