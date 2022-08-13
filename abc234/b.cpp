#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)(v.size())

#define chmax(a, b) a = max(a, b)

int main() {
  ll n;
  cin >> n;
  vector<double> x(n), y(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }
  double ans = 0;
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      chmax(ans, sqrt((x[i] - x[j]) * (x[i] - x[j]) +
                      (y[i] - y[j]) * (y[i] - y[j])));
    }
  }
  cout << fixed << setprecision(10) << ans << endl;
}