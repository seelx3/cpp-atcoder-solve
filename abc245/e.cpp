#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)v.size()

const ll inf = 100100100100;

int main() {
  ll n, m;
  cin >> n >> m;
  vector<ll> a(n), b(n), c(m), d(m);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n; i++)
    cin >> b[i];
  for (int i = 0; i < m; i++)
    cin >> c[i];
  for (int i = 0; i < m; i++)
    cin >> d[i];

  vector<pair<pair<ll, ll>, int>> vp;
  for (int i = 0; i < n; i++) {
    vp.push_back({{a[i], b[i]}, 0});
  }
  for (int i = 0; i < m; i++) {
    vp.push_back({{c[i], d[i]}, 1});
  }
  sort(ALL(vp), greater<>());

  set<ll> stw;
  map<ll, int> mp;
  stw.insert(inf);

  bool ok = true;
  for (int i = 0; i < sz(vp); i++) {
    ll wid = vp[i].first.second;
    if (vp[i].second == 1) { // box
      stw.insert(wid);
      mp[wid]++;
    } else { // choco
      auto it = *stw.lower_bound(wid);
      if (it == inf) {
        ok = false;
        break;
      }
      mp[it]--;
      if (mp[it] == 0) {
        stw.erase(it);
      }
    }
  }

  if (ok)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;

#ifdef DEBUG
  for (int i = 0; i < sz(vp); i++) {
    cout << vp[i].first.first << ", " << vp[i].first.second << ", "
         << vp[i].second << endl;
  }
#endif
}