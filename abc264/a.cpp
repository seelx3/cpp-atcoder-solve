#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)v.size()

int main() {
  string s = "atcoder";
  int l, r;
  cin >> l >> r;
  l--;
  cout << s.substr(l, r - l) << endl;
}