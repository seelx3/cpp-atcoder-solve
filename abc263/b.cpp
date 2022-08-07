#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)v.size()

int main() {
  ll n;
  cin >> n;
  vector<ll> p(n);
  for (int i = 1; i < n; i++) {
    cin >> p[i];
    p[i]--;
  }

  ll ans = 0;
  ll now = n - 1;
  while (now != 0) {
    ans++;
    now = p[now];
  }

  cout << ans << endl;
}