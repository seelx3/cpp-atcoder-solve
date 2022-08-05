#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)v.size()

ll dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
ll dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

int main() {
  int n;
  cin >> n;
  vector<string> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  auto toint = [](char c) { return c - '0'; };
  ll ans = 0;
  for (int h = 0; h < n; h++) {
    for (int w = 0; w < n; w++) {
      for (int dir = 0; dir < 8; dir++) {
        ll tmp = 0;
        for (int i = 0; i < n; i++) {
          tmp *= 10;
          tmp += toint(a[(h + dx[dir] * i + n) % n][(w + dy[dir] * i + n) % n]);
        }
        ans = max(ans, tmp);
      }
    }
  }
  cout << ans << endl;
}