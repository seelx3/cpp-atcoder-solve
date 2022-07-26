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
  ll n, m;
  cin >> n >> m;
  multiset<ll> a;
  vector<ll> b(m);
  for(int i = 0; i < n; i++) { 
    ll x;
    cin >> x;
    a.insert(x);
  }
  for(int i = 0; i < m; i++) { cin >> b[i]; }

  for(int i = 0; i < m; i++) {
    if(!a.count(b[i])) {
      cout << "No" << endl;
      return 0;
    }
    a.erase(a.find(b[i]));
  }
  cout << "Yes" << endl;
}