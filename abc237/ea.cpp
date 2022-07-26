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

int main() {
  ll n, m;
  cin >> n >> m;
  vector<ll> h(n);
  for(int i = 0; i < n; i++) { cin >> h[i]; }
  vector<vector<pair<ll, ll>>> G(n);
  for(int i = 0; i < m; i++) { 
    int u, v;
    cin >> u >> v;
    u--; v--;
    G[u].push_back({(h[u] > h[v] ? 0 : abs(h[u] - h[v])), v});
    G[v].push_back({(h[v] > h[u] ? 0 : abs(h[u] - h[v])), u});
  }

  vector<ll> d(n, INF);
  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
  d[0] = -h[0];
  pq.push({d[0], 0});
  while(!pq.empty()) {
    ll pot = pq.top().first;
    ll v = pq.top().second;
    // cout << v+1 << " " << pot << endl;
    pq.pop();
    for(auto u : G[v]) {
      if(pot+u.first < d[u.second]) {
        pq.push({pot+u.first, u.second});
        d[u.second] = pot+u.first;
      }
    }
  }

  ll ans = -INF;
  for(int i = 0; i < n; i++) {
    chmax(ans, -(d[i] + h[i]));
  }
  cout << ans << endl;
}