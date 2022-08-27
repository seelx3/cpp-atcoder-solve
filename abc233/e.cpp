#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)(v.size())

const int max_n = 500100;

int main() {
  string x;
  cin >> x;

  reverse(ALL(x));
  vector<ll> v(max_n);
  for (int i = 0; i < sz(x); i++) {
    v[i] = x[i] - '0';
  }
  reverse(ALL(v));
  for (int i = 1; i < max_n; i++) {
    v[i] = v[i] + v[i - 1];
  }
  reverse(ALL(v));

  string ans = "";
  for (int i = 0; i < max_n - 1; i++) {
    ll r = v[i] % 10;
    v[i + 1] += v[i] / 10;
    ans.push_back('0' + r);
  }
  reverse(ALL(ans));
  for (int i = 0; i < sz(ans); i++) {
    if (ans[i] != '0') {
      cout << ans.substr(i, sz(ans) - i + 1) << endl;
      return 0;
    }
  }
}