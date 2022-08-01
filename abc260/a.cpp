#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)v.size()

int main() {
  string s;
  cin >> s;
  if (s[0] != s[1] && s[0] != s[2])
    cout << s[0] << endl;
  else if (s[1] != s[0] && s[1] != s[2])
    cout << s[1] << endl;
  else if (s[2] != s[0] && s[2] != s[1])
    cout << s[2] << endl;
  else
    cout << -1 << endl;
}