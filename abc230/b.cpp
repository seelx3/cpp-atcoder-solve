#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)(v.size())

int main() {
  string s;
  cin >> s;
  string t = "oxxoxxoxxoxxoxxoxx";
  if (s == t.substr(0, sz(s)) || s == t.substr(1, sz(s)) ||
      s == t.substr(2, sz(s))) {
    cout << "Yes" << endl;
  } else
    cout << "No" << endl;
}