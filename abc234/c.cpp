#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)(v.size())

int main() {
  ll k;
  cin >> k;
  string ans = "";
  bool flg = false;
  for (int i = 62; i >= 0; i--) {
    if ((k >> i) & 1) {
      ans += '2';
      flg = true;
    } else {
      if (flg)
        ans += '0';
    }
  }
  cout << ans << endl;
}