#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)v.size()

int main() {
  ll h, w;
  cin >> h >> w;
  vector<string> s(h);
  for (int i = 0; i < h; i++) {
    cin >> s[i];
  }

  vector<pair<ll, ll>> vp;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (s[i][j] == 'o')
        vp.push_back({i, j});
    }
  }

  cout << abs(vp[0].first - vp[1].first) + abs(vp[0].second - vp[1].second)
       << endl;
}