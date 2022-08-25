#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)(v.size())

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> p(n);
  for (int i = 0; i < n; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    p[i] = a + b + c;
  }
  vector<int> v = p;
  sort(ALL(v));
  for (int i = 0; i < n; i++) {
    if (upper_bound(ALL(v), p[i] + 300) - 1 - v.begin() >= n - k)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
}