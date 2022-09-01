#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)(v.size())

int main() {
  ll n, m;
  cin >> n >> m;
  vector<vector<ll>> b(n, vector<ll>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> b[i][j];
    }
  }

  bool ok = true;

  // ver
  for (int j = 0; j < m; j++) {
    for (int i = 0; i < n - 1; i++) {
      if (b[i + 1][j] != b[i][j] + 7)
        ok = false;
    }
  }

  // holi
  for (int j = 0; j < m - 1; j++) {
    if (b[0][j + 1] != b[0][j] + 1)
      ok = false;
  }
  if ((b[0][0] - 1) / 7 != (b[0][m - 1] - 1) / 7)
    ok = false;

  cout << (ok ? "Yes" : "No") << endl;
}