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

const int inf = 100100100;

int main(){
  int n, m;
  cin >> n >> m;
  vector<vector<int>> G(n);
  for(int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--; v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  vector<vector<int>> d(1<<n, vector<int>(n, inf));
  queue<pair<int, int>> qu;
  for(int i = 0; i < n; i++) { 
    d[1<<i][i] = 1;
    qu.push({1<<i, i});
  }

  while(!qu.empty()) {
    int s = qu.front().first;
    int u = qu.front().second;
    qu.pop();
    for(auto v : G[u]) {
      if(d[s^(1<<v)][v] <= d[s][u]+1) continue;
      d[s^(1<<v)][v] = d[s][u]+1;
      qu.push({s^(1<<v), v});
    }
  }

  ll ans = 0;
  for(int i = 1; i < (1<<n); i++) {
    int mn = inf;
    for(int j = 0; j < n; j++) {
      chmin(mn, d[i][j]);
    }
    ans += mn;
  }

  cout << ans << endl;

  return 0;
}