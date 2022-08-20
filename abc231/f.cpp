#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)(v.size())

template <typename T> struct BIT {
  int n;         // 配列の要素数(数列の要素数+1)
  vector<T> bit; // データの格納先
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
  vector<ll> a(n), b(n);
  set<ll> st;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    st.insert(a[i]);
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    st.insert(b[i]);
  }

  vector<ll> c;
  for (auto it : st) {
    c.push_back(it);
  }
  sort(ALL(c));

  for (int i = 0; i < n; i++) {
    a[i] = (lower_bound(ALL(c), a[i]) - c.begin()) + 1;
    b[i] = (lower_bound(ALL(c), b[i]) - c.begin()) + 1;
  }

  vector<pair<ll, ll>> p(n);
  for (int i = 0; i < n; i++) {
    p[i] = {a[i], b[i]};
  }
  sort(ALL(p));
  for (int i = 0; i < n; i++) {
    a[i] = p[i].first;
    b[i] = p[i].second;
  }

#ifdef DEBUG
  for (int i = 0; i < n; i++) {
    cout << a[i] << " \n"[i == n - 1];
  }
  for (int i = 0; i < n; i++) {
    cout << b[i] << " \n"[i == n - 1];
  }
#endif

  BIT<ll> bb(sz(c) + 1);

  ll ans = 0;
  int j = 0;
  for (int i = 0; i < n; i++) {
    int j_max = upper_bound(ALL(a), a[i]) - a.begin();
    while (j < j_max) {
      bb.add(b[j], 1);
      j++;
    }
    ans += j_max - bb.sum(b[i] - 1);
#ifdef DEBUG
    cout << i + 1 << " : ans = " << ans << "-----------" << endl;
    // for (int j = 0; j < sz(c) + 1; j++) {
    //   cout << bb.sum(j) << " \n"[j == sz(c)];
    // }
    cout << "j_max = " << j_max << endl;
    // cout << "b[i] = " << b[i] << endl;
    // cout << "bb.sum(b[i]-1) = " << bb.sum(b[i] - 1) << endl;
#endif
  }

  cout << ans << endl;
}