#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)(v.size())

int main() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  vector<ll> a_od, a_ev;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (i % 2 == 0)
      a_od.push_back(a[i]);
    else
      a_ev.push_back(a[i]);
  }
  sort(ALL(a));
  ll ans = 0;
  for (int i = 0; i < sz(a_od); i++) {
    int pos = lower_bound(ALL(a), a_od[i]) - a.begin();
    if (pos % 2 != 0)
      ans++;
  }
  cout << ans << endl;
}