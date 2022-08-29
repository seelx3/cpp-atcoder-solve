#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)(v.size())

int main() {
  ll n;
  cin >> n;
  set<vector<ll>> st;
  for (ll i = 0; i < n; i++) {
    ll L;
    cin >> L;
    vector<ll> v(L);
    for (ll j = 0; j < L; j++) {
      cin >> v[j];
    }
    st.insert(v);
  }
  cout << sz(st) << endl;
}