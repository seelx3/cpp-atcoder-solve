#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)(v.size())

int main() {
  string s;
  cin >> s;
  if (s.substr(sz(s) - 2, 2) == "er") {
    cout << "er" << endl;
  } else {
    cout << "ist" << endl;
  }
}