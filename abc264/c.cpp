#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)v.size()

int main() {
  int h1, w1, h2, w2;
  cin >> h1 >> w1;
  vector<vector<ll>> a(h1, vector<ll>(w1));
  for (int i = 0; i < h1; i++) {
    for (int j = 0; j < w1; j++) {
      cin >> a[i][j];
    }
  }
  cin >> h2 >> w2;
  vector<ll> b;
  for (int i = 0; i < h2; i++) {
    for (int j = 0; j < w2; j++) {
      ll c;
      cin >> c;
      b.push_back(c);
    }
  }

  for (int tmp = 0; tmp < (1 << h1); tmp++) {
    bitset<20> s1(tmp);
    for (int tmp2 = 0; tmp2 < (1 << w1); tmp2++) {
      bitset<20> s2(tmp2);
      vector<ll> bb;
      for (int i = 0; i < h1; i++) {
        if (!s1.test(i))
          continue;
        for (int j = 0; j < w1; j++) {
          if (s2.test(j))
            bb.push_back(a[i][j]);
        }
      }
      if (bb == b) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }

  cout << "No" << endl;
}