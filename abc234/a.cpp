#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)(v.size())

int main() {
  ll t;
  cin >> t;

  auto f = [](ll x) -> ll { return x * x + 2 * x + 3; };

  cout << f(f(f(t) + t) + f(f(t))) << endl;
}