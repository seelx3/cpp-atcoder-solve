#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)(v.size())

#define chmin(a, b) a = min(a, b)

int main() {
  ll n, m;
  cin >> n >> m;
  vector<ll> a(n + 1), b(m + 1), c(n + m + 1);
  int pos = 105;
  for (int i = 0; i < n + 1; i++) {
    cin >> a[i];
    if (a[i] != 0)
      chmin(pos, i);
  }
  for (int i = 0; i < n + m + 1; i++) {
    cin >> c[i];
  }

  for (int i = 0; i < m + 1; i++) {
    ll mins = 0;
    ll cs = i + pos;
#ifdef DEBUG
    cout << i << ": " << (c[cs] - mins) / a[pos] << endl;
#endif
    // mins += b[j] * a[i + pos - j];
    for (int j = pos + 1; j <= cs; j++) {
      if (j > n || cs - j > m)
        continue;
#ifdef DEBUG
      cout << "a[" << j << "] = " << a[j] << ", b[cs - j] = " << b[cs - j]
           << endl;
#endif
      mins += a[j] * b[cs - j];
    }
    b[i] = (c[cs] - mins) / a[pos];
  }

  for (int i = 0; i < m + 1; i++) {
    cout << b[i] << " \n"[i == m];
  }
}