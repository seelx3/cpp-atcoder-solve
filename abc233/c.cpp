#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)(v.size())

const ll x_max = 1'000'000'000'000'000'000;

bool overflow(ll a, ll b) { return (LONG_LONG_MAX / a) < b; }

int main() {
  ll n, x;
  cin >> n >> x;
  vector<vector<ll>> a(n);
  for (int i = 0; i < n; i++) {
    ll l;
    cin >> l;
    for (int j = 0; j < l; j++) {
      ll b;
      cin >> b;
      a[i].push_back(b);
    }
  }

  ll ans = 0;
  function<void(int, ll)> dfs = [&](int k, ll m) -> void {
    if (m > x_max)
      return;
    if (k == n) {
      if (m == x)
        ans++;
    } else {
      for (auto it : a[k]) {
        if (!overflow(m, it)) {
          dfs(k + 1, m * it);
        }
      }
    }
  };

  dfs(0, 1);
  cout << ans << endl;
}