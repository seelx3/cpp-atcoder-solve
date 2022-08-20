#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)(v.size())

int main() {
  ll n, x;
  string s;
  cin >> n >> x >> s;

  string t = "";
  int u_cnt = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == 'U') {
      u_cnt++;
    } else {
      if (u_cnt) {
        u_cnt--;
      } else {
        t.push_back(s[i]);
      }
    }
  }
  while (u_cnt--) {
    t.push_back('U');
  }
  reverse(ALL(t));

#ifdef DEBUG
  cout << t << endl;
#endif

  for (int i = 0; i < sz(t); i++) {
    if (t[i] == 'U') {
      x /= 2;
    } else if (t[i] == 'L') {
      x *= 2;
    } else if (t[i] == 'R') {
      x = x * 2 + 1;
    }
  }

  cout << x << endl;
}