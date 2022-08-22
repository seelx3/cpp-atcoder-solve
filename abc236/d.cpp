#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)(v.size())

#define chmax(a, b) a = max(a, b)
using VI = vector<int>;
using VP = vector<pair<int, int>>;

int main() {
  ll n;
  cin >> n;
  vector<vector<ll>> a(2 * n + 1, vector<ll>(2 * n + 1));
  for (int i = 1; i < 2 * n; i++) {
    for (int j = i + 1; j <= 2 * n; j++) {
      cin >> a[i][j];
    }
  }

  vector<int> s;
  for (int i = 1; i <= 2 * n; i++) {
    s.push_back(i);
  }

  ll ans = 0;
  function<void(VI, VP)> f = [&](VI vi, VP vp) -> void {
    if (sz(vi) == 0) {
      ll tmp = 0;
      for (auto [u, v] : vp) {
        tmp ^= a[u][v];
      }
      chmax(ans, tmp);
      return;
    }
    for (int i = 1; i < sz(vi); i++) {
      VP nxvp = vp;
      VI nxvi = vi;
      nxvi.erase(remove(ALL(nxvi), vi[0]), nxvi.end());
      nxvi.erase(remove(ALL(nxvi), vi[i]), nxvi.end());
      nxvp.push_back({vi[0], vi[i]});
      f(nxvi, nxvp);
    }
    return;
  };

  f(s, {});
  cout << ans << endl;
}