#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)(v.size())

int main() {
  ll a, b, c;
  cin >> a >> b;
  c = a + b;
  string s = to_string(a);
  string t = to_string(b);
  string u = to_string(c);
  reverse(ALL(s));
  reverse(ALL(t));
  reverse(ALL(u));
  bool hard = false;
  for (int i = 0; i < min(sz(s), sz(t)); i++) {
    if (s[i] - '0' + t[i] - '0' >= 10)
      hard = true;
  }
  cout << (hard ? "Hard" : "Easy") << endl;
}