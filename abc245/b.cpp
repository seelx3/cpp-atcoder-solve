#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)v.size()

int main() {
  ll n;
  cin >> n;
  vector<bool> b(2100);
  for (int i = 0; i < n; i++) {
    ll a;
    cin >> a;
    b[a] = true;
  }
  for (int i = 0; i < 2100; i++) {
    if (!b[i]) {
      cout << i << endl;
      return 0;
    }
  }
}