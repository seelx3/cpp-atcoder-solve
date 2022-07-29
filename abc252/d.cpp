#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)v.size()

const int MX = 500500;

int main() {
  ll n;
  cin >> n;
  vector<ll> a(n), cnt(MX);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  sort(ALL(a));
  for (int i = 0; i < MX - 1; i++) {
    cnt[i + 1] += cnt[i];
  }
  ll ans = 0;
  for (int i = 1; i < n - 1; i++) {
    ans += cnt[a[i] - 1] * (n - cnt[a[i]]);
  }
  cout << ans << endl;
}