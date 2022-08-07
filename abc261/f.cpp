#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)v.size()

template <typename T> struct BIT {
  int n;
  vector<T> bit;
  BIT(int n_) : n(n_ + 1), bit(n, 0) {}
  void add(int i, T x) {
    i++;
    for (int idx = i; idx < n; idx += (idx & -idx)) {
      bit[idx] += x;
    }
  }
  T sum(int i) {
    i++;
    T s(0);
    for (int idx = i; idx > 0; idx -= (idx & -idx)) {
      s += bit[idx];
    }
    return s;
  }
  T sub_sum(int l, int r) {
    if (l == 0)
      return sum(r);
    else
      return sum(r) - sum(l - 1);
  }
};

int main() {
  ll n;
  cin >> n;
  vector<ll> c(n), x(n);
  for (int i = 0; i < n; i++)
    cin >> c[i];
  for (int i = 0; i < n; i++)
    cin >> x[i];

  // ans: i < j で c[i]!=c[j] かつ x[i] > x[j] となる組み合わせ(i, j)の個数
  // pre1: i < j で x[i] > x[j] となる組み合わせ(i, j)の個数
  // pre2: i < j で c[i]==c[j] かつ x[i] > x[j] となる組み合わせ(i, j)の個数
  // ref. 転倒数

  vector<vector<ll>> x_c(n + 1); // x_c[i] : cの値がiとなるようなxのvector
  for (int i = 0; i < n; i++) {
    x_c[c[i]].push_back(x[i]);
  }

  ll pre1 = 0;
  BIT<int> bit(n + 5);
  for (int i = 0; i < n; i++) {
    pre1 += (i - bit.sum(x[i]));
    bit.add(x[i], 1);
  }
  for (int i = 0; i < n; i++) {
    bit.add(x[i], -1);
  }
  // cout << pre1 << endl;

  ll pre2 = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < sz(x_c[i]); j++) {
      pre2 += (j - bit.sum(x_c[i][j]));
      bit.add(x_c[i][j], 1);
    }
    for (int j = 0; j < sz(x_c[i]); j++) {
      bit.add(x_c[i][j], -1);
    }
  }
  // cout << pre2 << endl;

  cout << pre1 - pre2 << endl;
}