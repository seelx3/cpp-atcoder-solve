#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)v.size()

int main() {
  ll n;
  cin >> n;
  vector<ll> s(n), t(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> t[i];
  }
  for (int i = 0; i < 2 * n; i++) {
    int now = i % n, nx = (i + 1) % n;
    t[nx] = min(t[nx], t[now] + s[now]);
  }
  for (int i = 0; i < n; i++) {
    cout << t[i] << endl;
  }
}