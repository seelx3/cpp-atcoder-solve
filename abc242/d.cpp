#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)v.size()

int main() {
  string s;
  cin >> s;
  ll Q;
  cin >> Q;

  function<int(ll, ll)> f = [&](ll t, ll k) -> char {
    if (t == 0) {
      return s[k] - 'A';
    }
    if (k == 0) {
      return ((s[0] - 'A') + t) % 3;
    }
    return (f(t - 1, k / 2) + 1 + (k % 2)) % 3;
  };

  for (int q = 0; q < Q; q++) {
    ll t, k;
    cin >> t >> k;
    k--;
    cout << char('A' + f(t, k)) << endl;
  }
}