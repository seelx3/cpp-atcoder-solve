#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)v.size()

int main() {
  vector<ll> a(3);
  for (int i = 0; i < 3; i++) {
    cin >> a[i];
  }
  ll b = a[1];
  sort(ALL(a));
  if (b == a[1])
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}