#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)(v.size())

int main() {
  ll t;
  cin >> t;
  while (t--) {
    ll n, m;
    cin >> n >> m;
    vector<ll> x(n), y(n);
    for (int i = 0; i < n; i++) {
      cin >> x[i] >> y[i];
    }
    vector<ll> bb(n);
    for (int i = 0; i < n; i++) {
      if (i == 0) {
        bb[i] = x[i] * y[i];
      } else {
        bb[i] = bb[i - 1] + x[i] * y[i];
      }
    }
    vector<ll> aa(n);
    for (int i = 0; i < n; i++) {
      if (i == 0) {
        aa[i] = x[i] * y[i] * (y[i] + 1) / 2;
      } else {
        aa[i] = aa[i - 1] + bb[i - 1] * y[i] + x[i] * y[i] * (y[i] + 1) / 2;
      }
    }

    ll ans = max(x[0], aa[n - 1]); // 両端の大きい方で初期化

    for (int i = 1; i < n; i++) {
      if (bb[i - 1] >= 0 && bb[i] < 0) {
        // bb[i-1] + x[i] * z >= 0 となるような最大の z をみつける
        int z = bb[i - 1] / (-x[i]);
#ifdef DEBUG
        cout << "i = " << i << " , " << z << endl;
#endif
        ans = max(ans, aa[i - 1] + bb[i - 1] * z + x[i] * z * (z + 1) / 2);
      }
    }

    cout << ans << endl;

#ifdef DEBUG
    for (int i = 0; i < n; i++) {
      cout << x[i] << " : " << bb[i] << ", " << aa[i] << endl;
    }
#endif
  }
}

/*
1
4 13
3 3
1 4
-5 2
-3 4
 */