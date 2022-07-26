#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)v.size()

int main() {
  ll n, c;
  cin >> n >> c;
  vector<vector<vector<int>>> f(30, vector<vector<int>>(n, vector<int>(2)));
  for (int i = 0; i < n; i++) {
    ll t, a;
    cin >> t >> a;
    if (i == 0) {
      if (t == 1) {
        for (int j = 0; j < 30; j++) {
          f[j][i][0] = 0 & ((a >> j) & 1);
          f[j][i][1] = 1 & ((a >> j) & 1);
        }
      } else if (t == 2) {
        for (int j = 0; j < 30; j++) {
          f[j][i][0] = 0 | ((a >> j) & 1);
          f[j][i][1] = 1 | ((a >> j) & 1);
        }
      } else if (t == 3) {
        for (int j = 0; j < 30; j++) {
          f[j][i][0] = 0 ^ ((a >> j) & 1);
          f[j][i][1] = 1 ^ ((a >> j) & 1);
        }
      }
      continue;
    }
    if (t == 1) { // and
      for (int j = 0; j < 30; j++) {
        f[j][i][0] = f[j][i - 1][0] & ((a >> j) & 1);
        f[j][i][1] = f[j][i - 1][1] & ((a >> j) & 1);
      }
    } else if (t == 2) { // or
      for (int j = 0; j < 30; j++) {
        f[j][i][0] = f[j][i - 1][0] | ((a >> j) & 1);
        f[j][i][1] = f[j][i - 1][1] | ((a >> j) & 1);
      }
    } else if (t == 3) { // xor
      for (int j = 0; j < 30; j++) {
        f[j][i][0] = f[j][i - 1][0] ^ ((a >> j) & 1);
        f[j][i][1] = f[j][i - 1][1] ^ ((a >> j) & 1);
      }
    }
  }

  ll x = c;
  for (int i = 0; i < n; i++) {
    ll ans = 0;
    for (int j = 0; j < 30; j++) {
      ans += f[j][i][(x >> j) & 1] * (1 << j);
    }
    x = ans;
    cout << ans << endl;
  }
}