#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)v.size()

int main() {
  ll v, a, b, c;
  cin >> v >> a >> b >> c;
  v %= (a + b + c);
  if (v < a) {
    cout << "F" << endl;
  } else if (v < a + b) {
    cout << "M" << endl;
  } else if (v < a + b + c) {
    cout << "T" << endl;
  }
}