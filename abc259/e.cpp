#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)v.size()

int main() {
  ll n;
  cin >> n;
  vector<ll> m(n);
  vector<vector<ll>> p(n), e(n);

  map<ll, ll> mp;
  for (int i = 0; i < n; i++) {
    cin >> m[i];
    for (int j = 0; j < m[i]; j++) {
      ll _p, _e;
      cin >> _p >> _e;
      mp[_p] = max(mp[_p], _e);
      p[i].push_back(_p);
      e[i].push_back(_e);
    }
  }

  map<pair<ll, ll>, int> pecnt;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m[i]; j++) {
      if (mp[p[i][j]] == e[i][j]) { // p[i][j]の指数としてe[i][j]が最大のとき
        pecnt[{p[i][j], e[i][j]}]++;
      }
    }
  }

  ll ans = 0;
  bool mxok = false;
  for (int i = 0; i < n; i++) {
    bool ok = true;
    for (int j = 0; j < m[i]; j++) {
      if (e[i][j] >= mp[p[i][j]]) {
        if (pecnt[{p[i][j], e[i][j]}] <= 1)
          ok = false;
      }
    }
    if (!ok)
      ans++;
    if (!mxok && ok) {
      mxok = true;
    }
  }

  cout << ans + mxok << endl;

  // for (auto it : mp) {
  //   cout << it.first << ", " << it.second << endl;
  // }
}

/*
4
1
2 1
1
5 1
1
7 1
1
11 1
*/