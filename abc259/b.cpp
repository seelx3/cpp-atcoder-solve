#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)v.size()

const double PI = acos(-1.0);

int main() {
  double a, b, d;
  cin >> a >> b >> d;

  double theta = 2.0 * PI * d / 360.0;
  cout << fixed << setprecision(10) << a * cos(theta) - b * sin(theta) << " "
       << a * sin(theta) + b * cos(theta) << endl;
}