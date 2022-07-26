#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)
#define ALL(v) v.begin(),v.end()
#define sz(v) (ll)v.size()
const ll INF = __LONG_LONG_MAX__;
const ll MOD = 998244353;
// const ll MOD = 1000000007;
ll dx[] = {1, 0, -1, 0};
ll dy[] = {0, 1, 0, -1};
const double PI = acos(-1.0);

/*---------------------------
---------------------------*/

int main(){
  int n, m, k, s, t, x;
  cin >> n >> m >> k >> s >> t >> x;
  s--;
  t--;
  x--;
  vector<vector<int>> G(n);
  
  for(int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  vector<ll> even(n), odd(n);
  even[s] = 1;

  vector<ll> tmpEven, tmpOdd;
  for(int i = 0; i < k; i++) {
    tmpEven = even;
    tmpOdd = odd;
    even.assign(n, 0);
    odd.assign(n, 0);
    for(int u = 0; u < n; u++) { // u -> v
      for(auto v : G[u]) {
        if(v == x) {
          even[v] =( even[v] + tmpOdd[u]) % MOD;
          odd[v] = (odd[v] + tmpEven[u]) % MOD;
        } else {
          even[v] = (even[v] + tmpEven[u]) % MOD;
          odd[v] = (odd[v] + tmpOdd[u]) % MOD;
        }
      }
    }
  }

  cout << even[t] << endl;

  return 0;
}