#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)v.size()

int main() {
  ll n, k;
  cin >> n >> k;
  vector<pair<ll, ll>> cors(n);
  for (int i = 0; i < n; i++) {
    cin >> cors[i].first >> cors[i].second;
  }
  if (k == 1) {
    cout << "Infinity" << endl;
    return 0;
  }

  function<bool(int, int, int)> colinear_check = [&](int a, int b,
                                                     int c) -> bool {
    ll dx1 = cors[b].first - cors[a].first;
    ll dx2 = cors[c].first - cors[a].first;
    ll dy1 = cors[b].second - cors[a].second;
    ll dy2 = cors[c].second - cors[a].second;
    return dx1 * dy2 - dx2 * dy1 == 0;
  };

  vector<vector<bool>> seen(n, vector<bool>(n));
  ll ans = 0;
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (seen[i][j])
        continue;
      set<int> st;
      for (int k = 0; k < n; k++) {
        if (colinear_check(i, j, k))
          st.insert(k);
      }
      for (auto it1 : st) {
        for (auto it2 : st) {
          seen[it1][it2] = true;
        }
      }
      if (sz(st) >= k)
        ans++;
    }
  }
  cout << ans << endl;
}