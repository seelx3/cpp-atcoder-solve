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
  int n, q;
  cin >> n >> q;

  // 各頂点が20個までの頂点の情報を持てばよい

  vector<ll> x(n);
  for(int i = 0; i < n; i++) { cin >> x[i]; }

  vector<vector<int>> Tree(n);
  for(int i = 0; i < n-1; i++) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    Tree[a].push_back(b);
    Tree[b].push_back(a);
  }

  vector<vector<ll>> top20v(n);
  vector<ll> p(n); 

  vector<bool> seen(n);
  auto DFS = [&](auto dfs, ll u) -> void {
    seen[u] = true;
    vector<int> tmpLarge;
    tmpLarge.push_back(x[u]);
    for(ll i = 0; i < sz(Tree[u]); i++) {
      ll v = Tree[u][i];
      if(seen[v]) continue;
      p[v] = u;
      dfs(dfs, v);
      tmpLarge.insert(tmpLarge.end(), ALL(top20v[v]));
    }
    sort(ALL(tmpLarge), greater<>());
    for(int i = 0; i < min(20LL, sz(tmpLarge)); i++) { 
      top20v[u].push_back(tmpLarge[i]); 
    }
  };

  DFS(DFS, 0);

  for(int i = 0; i < q; i++) { 
    int v, k;
    cin >> v >> k;
    v--;
    cout << top20v[v][k-1] << endl;
  }
}