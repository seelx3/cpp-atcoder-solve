#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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
  ll x; 
  cin >> x;
  if( x < 0) {
    if( x%10 == 0 ) cout << x / 10 << endl;
    else cout << x / 10 - 1 << endl;
  } else {
    cout << x / 10 << endl;
  }
}