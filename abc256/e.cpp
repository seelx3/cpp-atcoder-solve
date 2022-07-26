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
  vector<int> x(n), c(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i];
    x[i]--;
  }
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }
  UnionFind uf(n);
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    if (!uf.issame(i, x[i])) {
      uf.merge(i, x[i]);
      continue;
    }
    int mincost = c[i];
    int v = i;
    do {
      v = x[v];
      mincost = min(mincost, c[v]);
    } while (v != i);
    ans += mincost;
  }
  cout << ans << endl;
}