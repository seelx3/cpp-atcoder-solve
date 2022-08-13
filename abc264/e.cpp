#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)(v.size())

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
  ll n, m, e;
  cin >> n >> m >> e;
  vector<ll> u(e), v(e);
  set<int> st;
  for (int i = 0; i < e; i++) {
    cin >> u[i] >> v[i];
    u[i]--;
    v[i]--;
    st.insert(i);
  }
  ll q;
  cin >> q;
  vector<ll> x(q);
  for (int i = 0; i < q; i++) {
    cin >> x[i];
    x[i]--;
    st.erase(x[i]);
  }

  UnionFind uf = UnionFind(n + m + 1);
  for (auto it : st) {
    uf.merge(u[it], v[it]);
  }

  for (int i = n; i < n + m - 1; i++) {
    uf.merge(i, i + 1); // 発電所をmerge
  }

  vector<ll> ans;
  for (int i = q - 1; i >= 0; i--) {
    ans.push_back(uf.size(n) - m);
    uf.merge(u[x[i]], v[x[i]]);
  }
  for (int i = q - 1; i >= 0; i--) {
    cout << ans[i] << endl;
  }
}