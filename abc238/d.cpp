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

void solve(){
  ll a, s;
  cin >> a >> s;
  ll sum = 0;
  bitset<60> bs(a);
  ll now = 1;
  for(int i = 0; i < 60; i++) {
    if(i) now *= 2;
    if(bs.test(i)) sum += now*2;
  }
  for(int i = 59; i >= 0; i--) {
    if(!bs.test(i) && (sum + now <= s)) sum += now;
    now /= 2;
  }
  cout << (sum == s ? "Yes" : "No") << endl;
}

int main(){
  ll t;
  cin >> t;
  for(int i = 0; i < t; i++) { solve(); };
}