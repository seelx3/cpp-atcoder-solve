#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)v.size()

int main() {
  ll n, m;
  cin >> n >> m;
  vector<ll> s(n - 1), x(m);
  for (int i = 0; i < n - 1; i++)
    cin >> s[i];
  for (int i = 0; i < m; i++) {
    cin >> x[i];
  }

  /**
   * e.g.
   * a[0] = z                             = z
   * a[2] = s[1] - s[0] + z               = z + t[2]
   * a[4] = s[3] - s[2] + s[1] - s[0] + z = z + t[4]
   *
   * a[1] = s[0] - z                      = - z - t[1]
   * a[3] = s[2] - s[1] + s[0] - z        = - z - t[3]
   *
   *
   * t[0] = 0
   * t[1] = -s[0]
   * t[2] = s[1] - s[0]
   * t[3] = -s[2] + s[1] - s[0]
   * t[4] = s[3] - s[2] + s[1] - s[0]
   *
   *
   * i%2 == 0 のとき
   * z = a[i] - t[i]
   *
   * i%2 != 0のとき
   * z = -a[i] - t[i]
   *
   * c[i][j] := a[i]==x[j]となるときのz(=a[0])の値
   * c[i][j](0<=i<n, 0<=j<m)に出現回数の最も多い値の出現回数が答えとなる
   */

  vector<ll> t(n);
  for (int i = 1; i < n; i++) {
    if (i % 2 == 0) {
      t[i] = t[i - 1] + s[i - 1];
    } else {
      t[i] = t[i - 1] - s[i - 1];
    }
  }

  map<ll, ll> mp;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      // a[i] == x[j] のときの a[0] を求める
      if (i % 2 == 0) {
        mp[x[j] - t[i]]++;
      } else {
        mp[-x[j] - t[i]]++;
      }
    }
  }

  ll z = 0;
  ll cnt = 0;
  for (auto it : mp) {
#ifdef DEBUG
    cout << it.first << " : " << it.second << endl;
#endif
    if (it.second > cnt) {
      cnt = it.second;
      z = it.first;
    }
  }

  cout << cnt << endl;

#ifdef DEBUG
  cout << z << endl;
#endif
}