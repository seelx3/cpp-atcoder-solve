#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)v.size()

int main() {
  ll n;
  cin >> n;
  map<ll, ll> mp;
  for (int i = 0; i < 4 * n - 1; i++) {
    ll a;
    cin >> a;
    mp[a]++;
  }
  for (auto it : mp) {
    if (it.second == 3) {
      cout << it.first << endl;
      return 0;
    }
  }
}