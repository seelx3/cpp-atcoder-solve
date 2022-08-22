#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)(v.size())

int main() {
  int x, y, n;
  cin >> x >> y >> n;
  if (3 * x <= y) {
    cout << n * x << endl;
  } else {
    cout << (n % 3) * x + (n / 3) * y << endl;
  }
}