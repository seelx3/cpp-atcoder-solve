#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)(v.size())

int main() {
  int l, r;
  cin >> l >> r;
  string s;
  cin >> s;

  string t = s.substr(l - 1, r - l + 1);
  reverse(ALL(t));

  for (int i = l - 1; i < r; i++) {
    s[i] = t[i - (l - 1)];
  }

  cout << s << endl;
}