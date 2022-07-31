#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)v.size()

int main() {
  ll n;
  cin >> n;
  string s;
  cin >> s;
  if (n == 2) {
    if (s[0] == s[1])
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
    return 0;
  }
  if (s[0] == 'A' && s[n - 1] == 'B')
    cout << "No" << endl;
  else
    cout << "Yes" << endl;
}