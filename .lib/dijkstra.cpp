#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)v.size()
const ll INF = 1e18;

struct edge {
  ll to, cost;
};
typedef pair<ll, ll> P;
struct graph {
  ll V;
  vector<vector<edge>> G;
  vector<ll> d;

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
    e.to = t, e.cost = cost;
    G[s].push_back(e);
  }

  void dijkstra(ll s) {
    for (ll i = 0; i < V; i++) {
      d[i] = INF;
    }
    d[s] = 0;
    priority_queue<P, vector<P>, greater<P>> que;
    que.push(P(0, s));
    while (!que.empty()) {
      P p = que.top();
      que.pop();
      ll v = p.second;
      if (d[v] < p.first)
        continue;
      for (auto e : G[v]) {
        if (d[e.to] > d[v] + e.cost) {
          d[e.to] = d[v] + e.cost;
          que.push(P(d[e.to], e.to));
        }
      }
    }
  }
};

// how to use

// make an n-vertex graph
// graph g(n);

// add edge (a -> b, cost)
// g.add_edge(a, b, cost);

// dijkstra from s
// g.dijkstra(s);

// Shortest path to each vertex
// g.d[i]