#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)(v.size())

int main() {
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n + 1), sum(n + 1);
  map<ll, int> mp = {{0, 1}};
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum[i] += sum[i - 1] + a[i];
    mp[sum[i]]++;
  }
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    if (mp.find(sum[i] + k) == mp.end()) {
      mp[sum[i]]--;
      continue;
    }
    if (k == 0) {
      ans += mp[sum[i] + k] - 1;
    } else {
      ans += mp[sum[i] + k];
    }
    mp[sum[i]]--;
  }
  cout << ans << endl;
}