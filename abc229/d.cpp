#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)(v.size())

int main() {
  string s;
  ll k;
  cin >> s >> k;
  ll n = sz(s);
  ll l = 0;
  ll r = 0;
  ll rest = k;
  while (r < n) {
    if (rest == 0 && s[r] == '.')
      break;
    if (s[r] == 'X') {
      r++;
    } else {
      rest--;
      r++;
    }
  }
  ll ans = r - l;
  while (true) {
    if (s[l] == '.')
      rest++;
    l++;
    while (rest > 0 || s[r] == 'X') {
      if (r == n) {
        ans = max(ans, r - l);
        cout << ans << endl;
        return 0;
      }
      if (s[r] == 'X')
        r++;
      else if (rest > 0) {
        r++;
        rest--;
      }
    }
    ans = max(ans, r - l);
  }
}