#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)v.size()

int main() {
  ll l1, r1, l2, r2;
  cin >> l1 >> r1 >> l2 >> r2;
  if (r1 < l2 || r2 < l1) {
    cout << 0 << endl;
  } else {
    cout << min(r1, r2) - max(l1, l2) << endl;
  }
}