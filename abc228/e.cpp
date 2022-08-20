#include <atcoder/all>
#include <bits/stdc++.h>
using namespace atcoder;
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)(v.size())

const ll MOD = 998244353;

int main() {
  ll n, k, m;
  cin >> n >> k >> m;
  if (m % MOD == 0)
    cout << 0 << endl;
  else
    cout << pow_mod(m, pow_mod(k, n, MOD - 1), MOD) << endl;
}