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

ll f(ll a, ll b) {
  return a*a*a + a*a*b + a*b*b + b*b*b;
}

int main(){
  ll n;
  cin >> n;

  ll ans = INF;
  int l, r, m;
  ll ret;
  for(int i = 0; i <= 1000000; i++) {
    l = -1, r = 1000001;
    while(l+1 < r) {
      m = (l+r)/2;
      ret = f(i, m);
      if(ret >= n){ 
        r = m;
        chmin(ans, ret);
      } else l = m;
    }
  }

  cout << ans << endl;
}