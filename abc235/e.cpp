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
  ll n, m, q;
  cin >> n >> m >> q;
  vector<pair<ll, pair<pair<ll, ll>, pair<bool, ll>>>> vp;
  for (int i = 0; i < m; i++) {
    ll a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    vp.push_back({c, {{a, b}, {false, 500500}}});
  }
  for (int i = 0; i < q; i++) {
    ll u, v, w;
    cin >> u >> v >> w;
    u--;
    v--;
    vp.push_back({w, {{u, v}, {true, i}}});
  }
  sort(ALL(vp));
  vector<string> ans(q);
  UnionFind uf = UnionFind(n);
  for (int i = 0; i < m + q; i++) {
    ll weight = vp[i].first;
    pair<ll, ll> p = vp[i].second.first;
    pair<ll, ll> q = vp[i].second.second;
    if (q.first) {
      if (uf.issame(p.first, p.second))
        ans[q.second] = "No";
      else
        ans[q.second] = "Yes";
    } else {
      if (uf.issame(p.first, p.second))
        continue;
      uf.merge(p.first, p.second);
    }
  }
  for (int i = 0; i < q; i++) {
    cout << ans[i] << endl;
  }
}