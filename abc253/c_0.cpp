#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)v.size()

ll INF = __LONG_LONG_MAX__ - 1;

int main() {
  ll q;
  cin >> q;

  set<pair<ll, ll>> sp;
  sp.insert({-1, -1});
  sp.insert({INF, INF});

  for (int i = 0; i < q; i++) {
    int id;
    cin >> id;
    if (id == 1) {
      ll x;
      cin >> x;
      auto p = *sp.lower_bound(make_pair(x, -INF));
      if (p.first != x) {
        sp.insert({x, 1});
      } else {
        sp.erase(p);
        sp.insert({p.first, p.second + 1});
      }
    } else if (id == 2) {
      ll x, c;
      cin >> x >> c;
      auto p = *sp.lower_bound(make_pair(x, -INF));
      if (p.first != x)
        continue;
      sp.erase(p);
      ll r = p.second - c;
      if (r > 0) {
        sp.insert({p.first, r});
      }
    } else if (id == 3) {
      sp.erase({-1, -1});
      sp.erase({INF, INF});
      cout << (*(sp.rbegin())).first - (*sp.begin()).first << endl;
      // cout << "i = " << i << endl;
      // for (auto p : sp) {
      //   cout << p.first << ", " << p.second << endl;
      // }
      sp.insert({-1, -1});
      sp.insert({INF, INF});
    }
  }
}