/**
 * !!!!! after_contest : WA
 */

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

ll n, m;
vector<vector<pair<ll, ll>>> G; // cost pos

int main(){
  cin >> n >> m;
  G.resize(n);
  vector<ll> h(n);
  for(int i = 0; i < n; i++) cin >> h[i];
  for(int i = 0; i < m; i++) {
    ll u, v;
    cin >> u >> v;
    u--;
    v--;
    ll dif = h[u] - h[v];
    G[u].push_back({(dif < 0 ? dif*2 : dif), v});
    dif = h[v] - h[u];
    G[v].push_back({(dif < 0 ? dif*2 : dif), u});
  }
  vector<ll> d(n, -INF);
  d[0] = 0;
  priority_queue<pair<ll, ll>> dq;
  dq.push({0, 0});
  while(!dq.empty()){
    ll cost = dq.top().first;
    ll pos = dq.top().second;
    // cout << "pos : " << pos << endl;
    dq.pop();
    for(auto e : G[pos]) {
      // cout << "hanbetu : " << e.second << endl;
      if(d[pos]+e.first > d[e.second]) { 
        d[e.second] = d[pos] + e.first;
        dq.push({d[e.second], e.second});
      }
    }
  }
  ll ans = -INF;
  for(int i = 0; i < n; i++) {
    chmax(ans, d[i]);
  } 
  cout << ans << endl;
}