#include <atcoder/all>
#include <bits/stdc++.h>
using namespace atcoder;
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)(v.size())

int main() {
  ll n, q;
  cin >> n >> q;
  dsu uf(n + 1);
  for (int i = 0; i < q; i++) {
    ll l, r;
    cin >> l >> r;
    uf.merge(l - 1, r);
  }
  if (uf.same(0, n))
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
