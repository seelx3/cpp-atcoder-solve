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
  int n;
  cin >> n;
  vector<vector<int>> Tree(n);
  for(int i = 0; i < n-1; i++) {
    ll u, v;
    cin >> u >> v;
    u--; v--;
    Tree[u].push_back(v);
    Tree[v].push_back(u);
  }

  vector<pair<int, int>> ran(n, {100100100, -100100100});
  int now = 1;
  vector<bool> seen(n);

  auto DFS = [&](auto dfs, int u) -> pair<int, int> {
    seen[u] = true;
    for(auto v : Tree[u]) {
      if(seen[v]) continue;
      auto p = dfs(dfs, v);
      chmin(ran[u].first, p.first);
      chmax(ran[u].second, p.second);
    }
    if(sz(Tree[u])==1 && u != 0) {
      ran[u] = {now, now};
      now++;
    }
    return ran[u];
  };

  DFS(DFS, 0);

  for(int i = 0; i < n; i++) {
    cout << ran[i].first << " " << ran[i].second << endl;
  }

}