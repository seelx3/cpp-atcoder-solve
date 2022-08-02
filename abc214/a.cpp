#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)v.size()

int main() {
  ll n;
  cin >> n;
  if (n <= 125)
    cout << 4 << endl;
  else if (n <= 211)
    cout << 6 << endl;
  else
    cout << 8 << endl;
}