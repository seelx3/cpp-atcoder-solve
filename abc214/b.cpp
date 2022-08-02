#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)v.size()

int main() {
  ll s, t;
  cin >> s >> t;
  ll ans = 0;
  for (int a = 0; a <= 100; a++) {
    for (int b = 0; b <= 100; b++) {
      for (int c = 0; c <= 100; c++) {
        if (a + b + c <= s && a * b * c <= t)
          ans++;
      }
    }
  }
  cout << ans << endl;
}