#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)v.size()

int main() {
  string s;
  cin >> s;
  vector<bool> b(10);
  for (int i = 0; i < 9; i++) {
    b[s[i] - '0'] = true;
  }
  for (int i = 0; i < 10; i++) {
    if (!b[i])
      cout << i << endl;
  }
}