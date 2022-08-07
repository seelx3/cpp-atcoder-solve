#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)v.size()

int main() {
  vector<int> v(5);
  for (int i = 0; i < 5; i++) {
    cin >> v[i];
  }

  sort(ALL(v));
  bool ok = false;
  if (v[0] == v[1] && v[1] == v[2] && v[3] == v[4] && v[2] != v[3])
    ok = true;
  if (v[0] == v[1] && v[2] == v[3] && v[3] == v[4] && v[2] != v[1])
    ok = true;

  if (ok)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}