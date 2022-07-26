#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)
#define ALL(v) v.begin(),v.end()
#define sz(v) (ll)v.size()
const ll INF = 1e18;
const ll MOD = 998244353;
// const ll MOD = 1000000007;
ll dx[] = {1, 0, -1, 0};
ll dy[] = {0, 1, 0, -1};
const double PI = acos(-1.0);

/*---------------------------

---------------------------*/

int main(){
  ll n;
  cin >> n;

  string s = to_string(n);
  ll len = sz(s);
  
  ll ans = 0;
  ll m = 9;
  for(int i = 1; i < len; i++) {
    if(i > 1) m *= 10; 
    ans = (ans + ((m%MOD)*((m+1)%MOD)/2)) % MOD;
  }

  ll minus = 10;
  for(int i = 0; i < len-2; i++) { minus *= 10; };
  if(len == 1) minus = 0;
  ll af = n - minus;
  if(len != 1) af += 1;
  ans = (ans + ((af%MOD)*((af+1)%MOD)/2)) % MOD;
  cout << ans << endl;
}