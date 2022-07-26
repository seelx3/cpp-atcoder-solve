#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)v.size()

int main() {
  ll n;
  cin >> n;
  vector<vector<char>> a(n, vector<char>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }

  bool ok = true;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (a[i][j] == 'D' && a[j][i] == 'D')
        continue;
      if (a[i][j] == 'L' && a[j][i] == 'W')
        continue;
      if (a[i][j] == 'W' && a[j][i] == 'L')
        continue;
      ok = false;
    }
  }

  cout << (ok ? "correct" : "incorrect") << endl;
}