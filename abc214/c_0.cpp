#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)v.size()

const ll INF = LONG_LONG_MAX;

int main() {
  ll n;
  cin >> n;
  vector<ll> s(n), t(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
  for (int i = 0; i < n; i++) {
    ll t;
    cin >> t;
    pq.push({t, i});
  }
  vector<ll> ans(n, INF);
  set<ll> st;
  while (true) {
    if (sz(st) == n)
      break;
    auto tp = pq.top();
    pq.pop();
    // cout << tp.second << ", " << tp.first << endl;
    ans[tp.second] = min(ans[tp.second], tp.first);
    st.insert(tp.second);
    pq.push({tp.first + s[tp.second], (tp.second + 1) % n});
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] << endl;
  }
}