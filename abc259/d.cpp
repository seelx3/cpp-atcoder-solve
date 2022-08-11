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

int check(ll x1, ll y1, ll x2, ll y2, ll r) {
  // (x1, y1)と(x2, y2)の距離がrと一致するとき0
  // 2点間距離がrより大きいとき1
  // 2点間距離がrより小さいとき-1を返す
  ll dist = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
  if (dist == r)
    return 0;
  else if (dist > r)
    return 1;
  else
    return -1;
}

int main() {
  ll n;
  cin >> n;
  ll sx, sy, tx, ty;
  cin >> sx >> sy >> tx >> ty;
  vector<ll> x(n), y(n), r(n);
  set<int> incs, inct;
  UnionFind uf = UnionFind(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i] >> r[i];
    if (check(sx, sy, x[i], y[i], r[i] * r[i]) == 0)
      incs.insert(i);
    if (check(tx, ty, x[i], y[i], r[i] * r[i]) == 0)
      inct.insert(i);
  }

  // 円の交わりを調べる
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (check(x[i], y[i], x[j], y[j], (r[i] + r[j]) * (r[i] + r[j])) <= 0 &&
          check(x[i], y[i], x[j], y[j], (r[i] - r[j]) * (r[i] - r[j])) >= 0) {
        // 円が交わる
        uf.merge(i, j);
      }
    }
  }

#ifdef DEBUG
  cout << sz(incs) << " " << sz(inct) << endl;
#endif

  bool ans = false;
  for (auto c1 : incs) {
    for (auto c2 : inct) {
#ifdef DEBUG
      cout << c1 << ", " << c2 << endl;
#endif
      if (uf.issame(c1, c2))
        ans = true;
    }
  }

  if (ans)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}