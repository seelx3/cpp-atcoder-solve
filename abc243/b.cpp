#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)v.size()

int main() {
  int n;
  cin >> n;
  vector<ll> a(n), b(n);
  set<ll> sta, stb;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  int ans1 = 0, ans2 = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == b[i])
      ans1++;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j)
        continue;
      if (a[i] == b[j])
        ans2++;
    }
  }
  cout << ans1 << endl;
  cout << ans2 << endl;
}