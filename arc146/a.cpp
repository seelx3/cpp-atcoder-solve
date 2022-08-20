#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)(v.size())

#define chmax(a, b) a = max(a, b)

int main() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(ALL(a), greater<ll>());
  vector<string> vs = {to_string(a[0]), to_string(a[1]), to_string(a[2])};
  string ans = "";
  sort(ALL(vs));
  do {
    chmax(ans, vs[0] + vs[1] + vs[2]);
  } while (next_permutation(ALL(vs)));
  cout << ans << endl;
}