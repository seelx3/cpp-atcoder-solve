#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)v.size()

int main() {
  ll n, m;
  cin >> n >> m;
  vector<vector<ll>> G(n);

  for (int i = 0; i < m; i++) {
    ll a, b;
    cin >> a >> b;
    a--;
    b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  set<ll> st;

  function<void(ll, ll)> dfs = [&](ll u, ll k) -> void {
    st.insert(u);
    for (auto v : G[u]) {
      if (k - 1 >= 0)
        dfs(v, k - 1);
    }
    return;
  };

  ll q;
  cin >> q;
  while (q--) {
    ll x, k;
    cin >> x >> k;
    x--;
    st.clear();
    dfs(x, k);
    ll ans = 0;
    for (auto it : st)
      ans += it + 1;
    cout << ans << endl;
  }
}