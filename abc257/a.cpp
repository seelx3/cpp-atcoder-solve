#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)v.size()

int main() {
  int n, x;
  cin >> n >> x;
  cout << (char)('A' + ((x - 1) / n)) << endl;
}