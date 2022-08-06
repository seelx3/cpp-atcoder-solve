#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)v.size()

int main() {
  int r, c;
  cin >> r >> c;
  r--;
  c--;
  vector<vector<int>> a(2, vector<int>(2));
  cin >> a[0][0] >> a[0][1] >> a[1][0] >> a[1][1];
  cout << a[r][c] << endl;
}