#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)(v.size())

int main() {
  string s;
  cin >> s;
  cout << s[((sz(s) + 1) / 2) - 1] << endl;
}