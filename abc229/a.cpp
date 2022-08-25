#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)(v.size())

int main() {
  string s1, s2;
  cin >> s1 >> s2;
  if ((s1 == ".#" && s2 == "#.") || (s1 == "#." && s2 == ".#"))
    cout << "No" << endl;
  else
    cout << "Yes" << endl;
}