#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)(v.size())

#define chmax(a, b) a = max(a, b)
const int inf = INT_MAX;

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  for (int i = 0; i < h; i++) {
    cin >> s[i];
  }

  vector<vector<int>> d(h, vector<int>(w, inf));
  d[0][0] = 1;

  queue<pair<int, int>> qu;
  qu.push({0, 0});
  int ans = 0;

  while (!qu.empty()) {
    auto [nowh, noww] = qu.front();
    chmax(ans, d[nowh][noww]);
    qu.pop();
    if (nowh + 1 < h && s[nowh + 1][noww] == '.' && d[nowh + 1][noww] == inf) {
      d[nowh + 1][noww] = d[nowh][noww] + 1;
      qu.push({nowh + 1, noww});
    }
    if (noww + 1 < w && s[nowh][noww + 1] == '.' && d[nowh][noww + 1] == inf) {
      d[nowh][noww + 1] = d[nowh][noww] + 1;
      qu.push({nowh, noww + 1});
    }
  }

  cout << ans << endl;
}