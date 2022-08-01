#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)v.size()

#define RED 0
#define BLUE 1

int main() {
  int n, x, y;
  cin >> n >> x >> y;

  function<ll(int, ll)> f = [&](int col, ll n) -> ll {
    if (col == RED) {
      if (n < 2)
        return 0;
      return f(RED, n - 1) + x * f(BLUE, n);
    } else {
      if (n < 2)
        return 1;
      return f(RED, n - 1) + y * f(BLUE, n - 1);
    }
  };

  cout << f(RED, n) << endl;
}