#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)(v.size())

int main() {
  ll n, k, a;
  cin >> n >> k >> a;
  a--;
  ll ans = (a + k) % n;
  cout << (ans != 0 ? ans : n) << endl;
}