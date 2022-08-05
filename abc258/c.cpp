#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)v.size()

int main() {
  ll n, q;
  string s;
  cin >> n >> q;
  cin >> s;
  int tp = 0;
  while (q--) {
    int t, x;
    cin >> t >> x;
    if (t == 1) {
      tp = (tp - x + n) % n;
    } else {
      cout << s[(tp + x - 1) % n] << endl;
    }
  }
}