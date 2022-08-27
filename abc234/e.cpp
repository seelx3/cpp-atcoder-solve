#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)(v.size())

int main() {
  ll x;
  cin >> x;

  set<string> set_s;

  for (int tp = 1; tp <= 9; tp++) { // 先頭の整数
    for (int d = -9; d <= 9; d++) { // 差
      string s = "";
      s.push_back('0' + tp);
      int nw = tp;
      while (true) {
        // cout << s << endl;
        set_s.insert(s);
        nw = nw + d;
        if (nw < 0 || nw >= 10)
          break;
        if (sz(s) > 17)
          break;
        s.push_back('0' + nw);
      }
    }
  }

  vector<ll> tousa;
  for (auto s : set_s) {
    tousa.push_back(stoll(s));
  }
  sort(ALL(tousa));
  for (auto a : tousa) {
    // cout << a << endl;
  }
  cout << *lower_bound(ALL(tousa), x) << endl;
}