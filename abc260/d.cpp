#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)v.size()

const ll inf = LONG_LONG_MAX;

int main() {
  ll n, k;
  cin >> n >> k;
  set<pair<ll, ll>> st;
  st.insert({inf, inf});

  vector<ll> route(n + 1, -1), ans(n + 1, -1);
  for (int i = 0; i < n; i++) {
    ll p;
    cin >> p;
    auto it = *st.lower_bound({p, -1});
    if (it.first == inf) { // 場にない
      st.insert({p, 1});
    } else {
      st.erase(it);
      route[p] = it.first;
      st.insert({p, it.second + 1});
    }
    it = *st.lower_bound({p, -1});
    if (it.second == k) {
      st.erase(it);
      int now = it.first;
      ans[now] = i + 1;
      while (route[now] != -1) {
        now = route[now];
        ans[now] = i + 1;
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << ans[i] << endl;
  }
}