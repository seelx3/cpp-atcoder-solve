#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)(v.size())

#define chmin(a, b) a = min(a, b)

int main() {
  ll n, k;
  cin >> n >> k;
  vector<ll> p(n);
  set<ll> st;
  ll now = 1001001001;
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    if (i < k) {
      chmin(now, p[i]);
      st.insert(p[i]);
    }
  }

  cout << now << endl;
  for (int i = k; i < n; i++) {
    st.insert(p[i]);
    if (p[i] > now) {
      now = *st.lower_bound(now + 1);
    }
    cout << now << endl;
  }
}