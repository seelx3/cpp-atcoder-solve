#include <atcoder/all>
#include <bits/stdc++.h>
using namespace atcoder;
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)(v.size())

int main() {
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n + 1), sum(n + 1);
  set<ll> st = {0};
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum[i] = sum[i - 1] + a[i];
    st.insert(sum[i]);
  }
#ifdef DEBUG
  for (int i = 0; i <= n; i++) {
    cout << sum[i] << " \n"[i == n];
  }
#endif
  vector<ll> v;
  fenwick_tree<ll> fw(n + 1);
  for (auto it : st) {
    v.push_back(it);
  }
  for (auto it : sum) {
    fw.add(lower_bound(ALL(v), it) - v.begin(), 1);
  }
#ifdef DEBUG
  for (int i = 0; i <= n; i++) {
    cout << fw.sum(i, i + 1) << " \n"[i == n];
  }
#endif
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    if (st.find(sum[i] + k) == st.end()) {
      fw.add(lower_bound(ALL(v), sum[i]) - v.begin(), -1);
      continue;
    }
    int l = lower_bound(ALL(v), sum[i] + k) - v.begin();
    if (k == 0) { // corner
      ans += fw.sum(l, l + 1) - 1;
    } else {
      ans += fw.sum(l, l + 1);
    }
    fw.add(lower_bound(ALL(v), sum[i]) - v.begin(), -1);
  }

#ifdef DEBUG
  for (int i = 0; i <= n; i++) {
    cout << fw.sum(i, i + 1) << " \n"[i == n];
  }
#endif

  cout << ans << endl;
}