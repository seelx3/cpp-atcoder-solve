#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)(v.size())

int main() {
  ll n, m;
  cin >> n >> m;
  vector<ll> a(n);
  ll common_num = 1;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
    common_num = lcm(common_num, a[i]);
  }

  for (int i = 0; i < n; i++) {
    if ((common_num / a[i]) % 2 == 0) {
      cout << 0 << endl;
      return 0;
    }
  }

  m *= 2;
  cout << (m / common_num) - (m / (common_num * 2)) << endl;
}