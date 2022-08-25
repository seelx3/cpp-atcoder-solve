#include <atcoder/all>
#include <bits/stdc++.h>
using namespace atcoder;
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)(v.size())

using mint = modint998244353;
const ll MOD = 998244353;

mint modpow(ll x, ll n) { return pow_mod(x, n, MOD); }

int main() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  set<ll> st;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    st.insert(a[i]);
  }
  vector<ll> set_vec;
  for (auto x : st) {
    set_vec.push_back(x);
  }
  for (int i = 0; i < n; i++) {
    a[i] = lower_bound(ALL(set_vec), a[i]) - set_vec.begin();
  }

  fenwick_tree<mint> ft(sz(st) + 5);

  mint ans = 0;
  ft.add(a[0], 1 / modpow(2, 0));
  for (int r = 1; r < n; r++) {
    // ans += sum_(a[l] < a[r] を満たす l について) 2^(r-l-1)
    // = sum ( 2^(r-1) * 2^(-l) )
    // = 2^(r-1) * sum ( 2^(-l) )
    ans += modpow(2, r - 1) * ft.sum(0, a[r] + 1);
    ft.add(a[r], 1 / modpow(2, r));
  }

  cout << ans.val() << endl;
}