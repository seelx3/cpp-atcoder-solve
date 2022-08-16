#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)(v.size())

int main() {
  ll x, y;
  cin >> x >> y;

  if (x < y) {
    cout << (y - x + 9) / 10 << endl;
  } else {
    cout << 0 << endl;
  }
}