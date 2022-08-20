#include <atcoder/all>
#include <bits/stdc++.h>
using namespace atcoder;
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)(v.size())

struct UnionFind {
  vector<int> par;
  vector<int> edge_cnt;
  set<int> roots;

  UnionFind(int n) : par(n, -1), edge_cnt(n, 0) {}
  void init(int n) {
    par.assign(n, -1);
    edge_cnt.assign(n, 0);
  }

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
      swap(x, y);
    par[x] += par[y];
    par[y] = x;
    return true;
  }

  int size(int x) { return -par[root(x)]; }

  void addedge(int x) { edge_cnt[root(x)]++; }

  void makeroots() {
    for (int i = 0; i < sz(par); i++) {
      roots.insert(root(i));
    }
  }
};

int main() {
  ll n, m;
  cin >> n >> m;
  vector<ll> u(m), v(m);
  UnionFind uf(n);
  for (int i = 0; i < m; i++) {
    cin >> u[i] >> v[i];
    u[i]--;
    v[i]--;
    uf.merge(u[i], v[i]);
  }
  if (n != m) {
    cout << 0 << endl;
    return 0;
  }
  for (int i = 0; i < m; i++) {
    uf.addedge(u[i]);
  }
  uf.makeroots();
  for (auto it : uf.roots) {
#ifdef DEBUG
    cout << "root = " << it << ", " << uf.size(it) << " " << uf.edge_cnt[it]
         << endl;
#endif
    if (uf.size(it) < 2 || uf.size(it) != uf.edge_cnt[it]) {
      cout << 0 << endl;
      return 0;
    }
  }
  modint998244353 ans = 1;
  for (int i = 0; i < sz(uf.roots); i++) {
    ans *= 2;
  }
  cout << ans.val() << endl;
}