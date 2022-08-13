#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)v.size()

int main() {
  string s, t;
  cin >> s;
  t = "atcoder";
  ll ans = 0;
  for (int i = 0; i < 7; i++) {
    int c = 0;
    for (int j = 0; j < sz(s); j++) {
      if (s[j] == t[i]) {
        c = j;
        break;
      }
    }
    ans += c;
    remove(ALL(s), t[i]);
  }
  cout << ans << endl;
}