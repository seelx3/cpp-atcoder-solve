#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)v.size()

struct UnionFind {
  vector<int> par;

  UnionFind(int n) : par(n, -1) {}
  void init(int n) { par.assign(n, -1); }

  int root(int x) {
    if (par[x] < 0)
      return x;
    else
      return par[x] = root(par[x]);
  }

  bool issame(int x, int y) { return root(x) == root(y); }

  bool merge(int x, int y) {
    x = root(x);
    y = root(y);
    if (x == y)
      return false;
    if (par[x] > par[y])
      swap(x, y); // merge technique
    par[x] += par[y];
    par[y] = x;
    return true;
  }

  int size(int x) { return -par[root(x)]; }
};

int main() {
  ll n;
  cin >> n;
  ll ans = 0;
  vector<pair<ll, pair<ll, ll>>> vp;
  for (int i = 0; i < n - 1; i++) {
    ll u, v, w;
    cin >> u >> v >> w;
    u--;
    v--;
    vp.push_back({w, {u, v}});
  }
  sort(ALL(vp));
  UnionFind uf = UnionFind(n);
  for (int i = 0; i < n - 1; i++) {
    ll w, u, v;
    w = vp[i].first;
    u = vp[i].second.first;
    v = vp[i].second.second;
    ans += w * uf.size(u) * uf.size(v);
    uf.merge(u, v);
  }
  cout << ans << endl;
}