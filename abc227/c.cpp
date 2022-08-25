#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)(v.size())

int main() {
  ll n;
  cin >> n;
  ll ans = 0;
  for (ll a = 1; a < 500000; a++) {
    if ((a * a * a) > n)
      break;
    for (ll b = a; b < 500000; b++) {
      if ((a * b * b) > n)
        break;
      // c <= n / (a*b)
      ans += n / (a * b) - (b - 1);
    }
  }

  cout << ans << endl;
}