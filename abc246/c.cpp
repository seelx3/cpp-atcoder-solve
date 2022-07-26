#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)
#define ALL(v) v.begin(),v.end()
#define sz(v) (ll)v.size()
const ll INF = __LONG_LONG_MAX__;
// const ll MOD = 998244353;
const ll MOD = 1000000007;
ll dx[] = {1, 0, -1, 0};
ll dy[] = {0, 1, 0, -1};
const double PI = acos(-1.0);

/*---------------------------
---------------------------*/

int main(){
  ll n, k, x;
  cin >> n >> k >> x;
  vector<ll> a(n);
  for(int i = 0; i < n; i++) { cin >> a[i]; }

  for(int i = 0; i < n; i++) {
    if(k==0) break;
    int cnt = a[i]/x;
    if(cnt > k) cnt = k;
    a[i] -= cnt*x;
    // cout << a[i] << endl;
    k -= cnt;
  }
  sort(ALL(a), greater<>());
  for(int i = 0; i < min(n, k); i++) {
    // cout << a[i] << endl;
    a[i] = 0;
  }
  ll ans = 0;
  for(int i = 0; i < n; i++) {
    ans += a[i];
  }
  cout << ans << endl;
}