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
  ll n;
  cin >> n;
  vector<ll> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];

  set<ll> st;
  st.insert(0);
  st.insert(360);
  ll now = 0;
  for(int i = 0; i < n; i++) {
    now = (now + a[i]) % 360;
    st.insert(now);
  }
  ll bf = 0;
  ll ans = 0;
  for(auto it : st) {
    chmax(ans, it - bf);
    bf = it;
  }
  cout << ans << endl;
}