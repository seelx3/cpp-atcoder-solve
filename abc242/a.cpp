#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)v.size()

int main() {
  int a, b, c, x;
  cin >> a >> b >> c >> x;
  if (x <= a)
    cout << 1 << endl;
  else if (x <= b)
    cout << fixed << setprecision(10) << (double)c / (double)(b - a) << endl;
  else
    cout << 0 << endl;
}