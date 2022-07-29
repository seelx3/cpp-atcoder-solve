#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)v.size()

const ll MX = 200100;

int main() {
  ll n;
  cin >> n;
  vector<vector<ll>> ids_of(n + 1);
  for (int i = 0; i < n + 1; i++) {
    ids_of[i].push_back(-1);
  }
  for (int i = 0; i < n; i++) {
    ll a;
    cin >> a;
    ids_of[a].push_back(i + 1);
  }
  for (int i = 0; i < n + 1; i++) {
    ids_of[i].push_back(MX);
  }
  ll q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    ll l, r, x;
    cin >> l >> r >> x;
    cout << upper_bound(ALL(ids_of[x]), r) - lower_bound(ALL(ids_of[x]), l)
         << endl;
  }
}