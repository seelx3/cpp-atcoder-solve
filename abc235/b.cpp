#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)v.size()

int main() {
  ll n;
  cin >> n;
  vector<ll> h(n);
  for (int i = 0; i < n; i++) {
    cin >> h[i];
  }

  ll now = 0;
  while (now != n - 1 && h[now] < h[now + 1])
    now++;
  cout << h[now] << endl;
}