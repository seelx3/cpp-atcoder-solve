#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)(v.size())

int main() {
  string s, t;
  cin >> s >> t;
  bool ok = false;
  for (int i = 0; i < 26; i++) {
    if (s == t)
      ok = true;
    for (int j = 0; j < sz(s); j++) {
      s[j] = 'a' + (s[j] - 'a' + 1) % 26;
    }
  }
  if (ok)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}