#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)
#define ALL(v) v.begin(),v.end()
#define sz(v) (ll)v.size()
const ll INF = 1e18;
// const ll MOD = 998244353;
const ll MOD = 1000000007;
ll dx[] = {1, 0, -1, 0};
ll dy[] = {0, 1, 0, -1};
const double PI = acos(-1.0);


/*---------------------------
---------------------------*/

int main(){
  ll n, l, w;
  cin >> n >> l >> w;
  vector<ll> a(n);

  a.push_back(-w);
  for(int i = 0; i < n; i++){
    ll x; cin >> x;
    a.push_back(x);
  }
  a.push_back(l);

  ll ans = 0;
  for (int i = 0; i < sz(a)-1; i++)
  {
    ll dif = max(a[i+1] - a[i] - w, 0LL);
    ans += (dif + w - 1) / w;
  }
  
  cout << ans << endl;
}