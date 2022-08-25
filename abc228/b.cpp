#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)(v.size())

int main() {
  ll n, x;
  cin >> n >> x;
  x--;
  vector<ll> a(n);
  vector<bool> seen(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
  }
  ll ans = 0;
  while (!seen[x]) {
    ans++;
    seen[x] = true;
    x = a[x];
  }
  cout << ans << endl;
}