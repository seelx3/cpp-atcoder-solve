#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)v.size()

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  if (a < c || (a == c && b <= d))
    cout << "Takahashi" << endl;
  else
    cout << "Aoki" << endl;
}