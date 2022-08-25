#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)(v.size())

int main() {
  ll n;
  cin >> n;

  set<ll> st;
  for (int i = 1; i <= 1000; i++) {
    for (int j = 1; j <= 1000; j++) {
      st.insert(4 * i * j + 3 * i + 3 * j);
    }
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    ll s;
    cin >> s;
    if (!st.count(s))
      ans++;
  }

  cout << ans << endl;
}