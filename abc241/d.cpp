#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)
#define ALL(v) v.begin(),v.end()
#define sz(v) (ll)v.size()
const ll INF = LONG_LONG_MAX;
// const ll MOD = 998244353;
const ll MOD = 1000000007;
ll dx[] = {1, 0, -1, 0};
ll dy[] = {0, 1, 0, -1};
const double PI = acos(-1.0);

/*---------------------------
easy method: multisetでlower_bound,upper_boundを使う
---------------------------*/

int main(){
  int Q;
  cin >> Q;
  multiset<ll> mlst;
  for(int i = 0; i < 5; i++) { mlst.insert(INF); };
  for(int i = 0; i < 5; i++) { mlst.insert(-INF); };
  while(Q--) {
    int T; cin >> T;
    ll x; int k;
    if(T == 1) {
      cin >> x;
      mlst.insert(x);
    }
    else if(T == 2) {
      cin >> x >> k;
      auto itr = mlst.upper_bound(x);
      while(k--) itr--;
      ll ans = *itr;
      if(ans != INF && ans != -INF) cout << ans << endl;
      else cout << -1 << endl;
    }
    else if(T == 3) {
      cin >> x >> k;
      auto itr = mlst.lower_bound(x);
      k--;
      while(k--) itr++;
      ll ans = *itr;
      if(ans != INF && ans != -INF) cout << ans << endl;
      else cout << -1 << endl;
    }
  }
}