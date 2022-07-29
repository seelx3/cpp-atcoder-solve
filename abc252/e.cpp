#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)v.size()
const ll INF = 1e18;

struct edge {
  ll to, from, cost;
};
typedef pair<ll, ll> P;
struct graph {
  ll V;
  vector<vector<edge>> G;
  vector<ll> d;
  ll dij_edge_cnt = 0;
  set<P> dij_edge;

  graph(ll n) { init(n); }

  void init(ll n) {
    V = n;
    G.resize(V);
    d.resize(V);
    for (ll i = 0; i < V; i++) {
      d[i] = INF;
    }
  }

  void add_edge(ll s, ll t, ll cost) {
    edge e;
    e.to = t, e.from = s, e.cost = cost;
    G[s].push_back(e);
  }

  void dijkstra(ll s) {
    for (ll i = 0; i < V; i++) {
      d[i] = INF;
    }
    d[s] = 0;
    priority_queue<pair<ll, P>, vector<pair<ll, P>>, greater<pair<ll, P>>> que;
    que.push({0, {s, s}});
    while (!que.empty()) {
      pair<ll, P> p = que.top();
      que.pop();
      ll v = p.second.second;
      if (d[v] < p.first)
        continue;
      dij_edge.insert({p.second.first, p.second.second});
      dij_edge.insert({p.second.second, p.second.first});
      dij_edge_cnt++;
      for (auto e : G[v]) {
        if (d[e.to] > d[v] + e.cost) {
          d[e.to] = d[v] + e.cost;
          que.push({d[e.to], {e.from, e.to}});
        }
      }
    }
  }
};

int main() {
  ll n, m;
  cin >> n >> m;
  vector<ll> a(m), b(m);
  graph G(n);
  for (int i = 0; i < m; i++) {
    ll c;
    cin >> a[i] >> b[i] >> c;
    a[i]--;
    b[i]--;
    G.add_edge(a[i], b[i], c);
    G.add_edge(b[i], a[i], c);
  }
  G.dijkstra(0);
  // cout << G.dij_edge_cnt << endl;
  vector<ll> ans;
  for (int i = 0; i < m; i++) {
    if (G.dij_edge.count({a[i], b[i]}))
      ans.push_back(i + 1);
  }
  for (int i = 0; i < sz(ans); i++) {
    cout << ans[i] << " \n"[i == sz(ans) - 1];
  }
}