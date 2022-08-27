#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)(v.size())

const ll MOD = 998244353;

int main() {
  ll n;
  cin >> n;
  // n - x = MOD * k
  // x = n - MOD * k
  if (n < 0) {
    n += ((-n) / MOD) * MOD + 6 * MOD;
  }
  n %= MOD;
  if (n == 0)
    cout << 0 << endl;
  else
    cout << n << endl;
}