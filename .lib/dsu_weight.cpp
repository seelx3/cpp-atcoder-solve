#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template <class T> struct UnionFind {
  vector<int> par;
  vector<int> rank;
  vector<T> diff_weight;

  UnionFind(int n = 1, T UNIT = 0) { init(n, UNIT); }

  void init(int n = 1, T UNIT = 0) {
    par.resize(n);
    rank.resize(n);
    diff_weight.resize(n);
    for (int i = 0; i < n; i++) {
      par[i] = i;
      rank[i] = 0;
      diff_weight[i] = UNIT;
    }
  }

  int root(int x) {
    if (par[x] == x) {
      return x;
    } else {
      int r = root(par[x]);
      diff_weight[x] += diff_weight[par[x]];
      return par[x] = r;
    }
  }

  T weight(int x) {
    root(x);
    return diff_weight[x];
  }

  bool issame(int x, int y) { return root(x) == root(y); }

  bool merge(int x, int y, T w) {
    w += weight(x);
    w -= weight(y);
    x = root(x);
    y = root(y);
    if (x == y)
      return false;
    if (rank[x] < rank[y]) {
      swap(x, y);
      w = -w;
    }
    if (rank[x] == rank[y])
      rank[x]++;
    par[y] = x;
    diff_weight[y] = w;
    return true;
  }

  T diff(int x, int y) { return weight(y) - weight(x); }
};

/**
 * merge(x, y)
 * issame(x, y, w)
 * diff(x, y)
 */

// practice: https://atcoder.jp/contests/abc087/tasks/arc090_b

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> l(m), r(m), d(m);
  for (int i = 0; i < m; i++) {
    cin >> l[i] >> r[i] >> d[i];
    l[i]--;
    r[i]--;
  }

  bool ans = true;
  UnionFind<int> uf(n);
  for (int i = 0; i < m; i++) {
    if (uf.issame(l[i], r[i])) {
      if (uf.diff(l[i], r[i]) != d[i]) {
        cout << "No" << endl;
        return 0;
      }
    } else {
      uf.merge(l[i], r[i], d[i]);
    }
  }
  cout << "Yes" << endl;
  return 0;
}