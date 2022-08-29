#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)(v.size())

int main() {
  double x;
  cin >> x;
  ll ans = int(x);
  ll y = int(x * 10);
  if (y % 10 >= 5)
    ans++;
  cout << ans << endl;
}