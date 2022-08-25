#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)(v.size())

int main() {
  int s, t, x;
  cin >> s >> t >> x;
  if (s < t) {
    if (x >= s && x < t)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  } else {
    if (x >= s || x < t)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
}