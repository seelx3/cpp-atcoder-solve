#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)v.size()

int main() {
  ll n, a, b;
  cin >> n >> a >> b;
  ll ans = ((n / a) * min(a, b) + min(n % a, b - 1)) - min((a - 1) % a, b - 1);
  cout << max(0LL, ans) << endl;
}