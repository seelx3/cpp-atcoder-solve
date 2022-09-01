#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)(v.size())

int main() {
  ll n;
  cin >> n;
  vector<ll> c(n);
  bool star = false;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    c[u]++;
    c[v]++;
    if (c[u] == n - 1 || c[v] == n - 1)
      star = true;
  }

  cout << (star ? "Yes" : "No") << endl;
}