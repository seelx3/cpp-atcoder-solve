#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(),v.end()
#define sz(v) (int)v.size()

#define pi pair<int, int>
#define ppi pair<int, pi>

const int INF = __INT_MAX__;

int main(){
  int n, m;
  cin >> n >> m;
  vector<vector<int>> G(n+1);
  for(int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--; v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  vector<vector<int>> d(n, vector<int>((1<<n), INF));
  priority_queue<ppi, vector<ppi>, greater<ppi>> pq;
  vector<int> path((1<<n), INF);

  for(int i = 0; i < n; i++) { d[i][0] = 0; }
  for(int i = 0; i < n; i++) { 
    d[i][(1<<i)] = 1; 
    path[(1<<i)] = 1;
    pq.push({1, {i, (1<<i)}});
  }

  path[0] = 0;

  while(!pq.empty()) {
    auto st = pq.top();
    pq.pop();
    int v = st.second.first;
    int S = st.second.second;
    for(auto u : G[v]) {
      int T = S^(1<<u);
      if(d[u][T] <= st.first+1) continue;
      d[u][T] = st.first+1;
      path[T] = min(path[T], d[u][T]);
      pq.push({d[u][T], {u, T}});
    }
  }

  ll ans = 0;
  for(int i = 0; i < (1<<n); i++) {
    ans += path[i];
  }

  cout << ans << endl;
}