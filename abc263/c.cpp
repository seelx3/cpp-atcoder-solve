#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)v.size()

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> ans;
  for (int tmp = 0; tmp < (1 << m); tmp++) {
    bitset<15> s(tmp);
    int cnt = 0;
    for (int i = 0; i < 15; i++) {
      if (s.test(i))
        cnt++;
    }
    if (cnt == n) {
      vector<int> vv;
      for (int i = 0; i < 15; i++) {
        if (s.test(i))
          vv.push_back(i + 1);
      }
      ans.push_back(vv);
    }
  }

  sort(ALL(ans));
  for (int i = 0; i < sz(ans); i++) {
    for (int j = 0; j < n; j++) {
      cout << ans[i][j] << " \n"[j == n - 1];
    }
  }
}