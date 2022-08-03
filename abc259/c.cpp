#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)v.size()

int main() {
  string s, t;
  cin >> s >> t;

  vector<pair<char, ll>> ss, tt;

  char c;
  int cnt = 0;
  for (int i = 0; i < sz(s); i++) {
    c = s[i];
    cnt = 1;
    while (s[i + 1] == s[i]) {
      cnt++;
      i++;
    }
    ss.push_back({c, cnt});
  }
  for (int i = 0; i < sz(t); i++) {
    c = t[i];
    cnt = 1;
    while (t[i + 1] == t[i]) {
      cnt++;
      i++;
    }
    tt.push_back({c, cnt});
  }
  bool ans = true;
  if (sz(ss) == sz(tt)) {
    for (int i = 0; i < sz(ss); i++) {
      if (!(ss[i].first == tt[i].first &&
            ((ss[i].second >= 2 && ss[i].second <= tt[i].second) ||
             (ss[i].second == 1 && ss[i].second == tt[i].second))))
        ans = false;
    }
  } else {
    ans = false;
  }
  cout << (ans ? "Yes" : "No") << endl;
}