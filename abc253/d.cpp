#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)v.size()

ll gcd(ll a, ll b) {
  if (a % b == 0)
    return b;
  return gcd(b, a % b);
}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

int main() {
  ll n, a, b;
  cin >> n >> a >> b;

  // (1~n)の総和 - aの倍数の総和 - bの倍数の総和 + lcm(a, b)の総和
  // sum_k=1^n(k) = k*(k+1)/2

  ll c = lcm(a, b);

  ll ans = 0;
  ans += n * (n + 1) / 2;
  ans -= a * ((n / a) * ((n / a) + 1) / 2);
  ans -= b * ((n / b) * ((n / b) + 1) / 2);
  ans += c * ((n / c) * ((n / c) + 1) / 2);

  cout << ans << endl;
}
