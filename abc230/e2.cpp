#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)(v.size())

int main() {
  ll n;
  cin >> n;
  ll ans = 0;
  ll k = (ll)(sqrt(n));
  // ans += sum _i=1 ^k [n/i]
  for (int i = 1; i <= k; i++) {
    ans += n / i;
  }
  if (n / k != k) {
    k++;
  }
  // ans += (残り)
  for (int i = 1; i < k; i++) {
    ans += ((n / i) - (n / (i + 1))) * i;
  }
  cout << ans << endl;
}