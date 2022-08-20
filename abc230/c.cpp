#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)(v.size())

int main() {
  ll n, a, b, p, q, r, s;
  cin >> n >> a >> b >> p >> q >> r >> s;
  for (int i = 0; i <= q - p; i++) {
    for (int j = 0; j <= s - r; j++) {
      if (p + i - a == r + j - b || p + i - a == -(r + j - b))
        cout << "#";
      else
        cout << ".";
    }
    cout << endl;
  }
}