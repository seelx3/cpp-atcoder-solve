#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)(v.size())

int main() {
  ll x, y, a, b, c;
  cin >> x >> y >> a >> b >> c;

  vector<pair<ll, ll>> rect = {{x, y}, {y, x}};
  vector<tuple<ll, ll, ll>> perm = {{a, b, c}, {b, c, a}, {c, a, b}};

  bool ok = false;
  for (auto [h, w] : rect) {
    for (auto [s, t, u] : perm) {
      ll rest_h = h - ((s + w - 1) / w);
      if (rest_h <= 0)
        continue;
      vector<pair<ll, ll>> rest_rect = {{rest_h, w}, {w, rest_h}};
      for (auto [h2, w2] : rest_rect) {
        if (((t + h2 - 1) / h2) + ((u + h2 - 1) / h2) <= w2)
          ok = true;
      }
    }
  }

  cout << (ok ? "Yes" : "No") << endl;
}