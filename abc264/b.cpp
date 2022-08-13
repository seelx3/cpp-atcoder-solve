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

  const int W = 15;
  vector<vector<int>> s1(W, vector<int>(15, 0)), s2;
  s2 = s1;

  for (int i = 0; i < W; i++) {
    for (int j = 0; j < W; j++) {
      if (i == 0 || j == 0) {
        s1[i][j] = 1;
      } else {
        s1[i][j] = s1[i - 1][j - 1] ^ 1;
      }
    }
  }

  for (int i = W - 1; i >= 0; i--) {
    for (int j = W - 1; j >= 0; j--) {
      if (i == W - 1 || j == W - 1) {
        s2[i][j] = 1;
      } else {
        s2[i][j] = s2[i + 1][j + 1] ^ 1;
      }
    }
  }

  if (r + c <= W - 1) {
    cout << (s1[r][c] ? "black" : "white") << endl;
  } else {
    cout << (s2[r][c] ? "black" : "white") << endl;
  }

#ifdef DEBUG
  for (int i = 0; i < W; i++) {
    for (int j = 0; j < W; j++) {
      if (i + j < W) {
        if (s1[i][j]) {
          cout << "#"
               << " \n"[j == W - 1];
        } else {
          cout << "."
               << " \n"[j == W - 1];
        }
      } else {
        if (s2[i][j]) {
          cout << "#"
               << " \n"[j == W - 1];
        } else {
          cout << "."
               << " \n"[j == W - 1];
        }
      }
    }
  }
#endif
}