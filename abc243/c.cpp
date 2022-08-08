#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)v.size()

#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)

int main() {
  ll n;
  cin >> n;
  vector<ll> x(n), y(n);
  map<ll, ll> yl, yr;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
    yl[y[i]] = -1;
    yr[y[i]] = 1001001001;
  }
  string s;
  cin >> s;

  for (int i = 0; i < n; i++) {
    if (s[i] == 'L') {
      chmax(yl[y[i]], x[i]);
    } else {
      chmin(yr[y[i]], x[i]);
    }
  }

  bool ans = false;
  for (auto it : yl) {
    // cout << it.first << " : " << it.second << ", " << yr[it.first] << endl;
    if (it.second > yr[it.first])
      ans = true;
  }
  if (ans)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}