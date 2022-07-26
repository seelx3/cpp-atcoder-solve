#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)v.size()

int main() {
  ll n;
  cin >> n;
  vector<char> c(n);
  vector<ll> w(n);
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> w[i];
  }
  vector<pair<ll, char>> vp(n);
  for (int i = 0; i < n; i++) {
    vp[i] = {w[i], c[i]};
  }
  sort(ALL(vp));

  ll ans = 0, now = 0;
  for (int i = 0; i < n; i++) {
    if (vp[i].second == '1')
      now++;
  }
  ans = max(ans, now);
  int i = 0;
  while (i < n) {
    do {
      if (vp[i].second == '1')
        now--;
      else
        now++;
      i++;
    } while (vp[i - 1].first == vp[i].first);
    ans = max(ans, now);
  }
  cout << ans << endl;
}