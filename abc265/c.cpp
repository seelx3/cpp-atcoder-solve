#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)(v.size())

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> g(h + 2);
  string ud = "";
  for (int i = 0; i < w + 2; i++) {
    ud.push_back('.');
  }
  for (int i = 0; i < h + 2; i++) {
    if (i == 0 || i == h + 1) {
      g[i] = ud;
    } else {
      string s;
      cin >> s;
      s = "." + s + ".";
      g[i] = s;
    }
  }

#ifdef DEBUG
  for (int i = 0; i < h + 2; i++) {
    cout << g[i] << endl;
  }
#endif

  int t = 500 * 500 + 5;
  int nowh = 1, noww = 1;
  while (t > 0) {
    char c = g[nowh][noww];
    if (c == 'U') {
      int nxh = nowh - 1;
      if (g[nxh][noww] == '.') {
        break;
      }
      nowh--;
    } else if (c == 'D') {
      int nxh = nowh + 1;
      if (g[nxh][noww] == '.') {
        break;
      }
      nowh++;
    } else if (c == 'L') {
      int nxw = noww - 1;
      if (g[nowh][nxw] == '.') {
        break;
      }
      noww--;
    } else if (c == 'R') {
      int nxw = noww + 1;
      if (g[nowh][nxw] == '.') {
        break;
      }
      noww++;
    }
    t--;
  }

  if (t == 0) {
    cout << -1 << endl;
  } else {
    cout << nowh << " " << noww << endl;
  }
}