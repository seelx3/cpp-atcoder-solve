#include <atcoder/all>
#include <bits/stdc++.h>
using namespace atcoder;
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)(v.size())

template <class T> vector<T> make_vec(size_t a) { return vector<T>(a); }
template <class T, class... Ts> auto make_vec(size_t a, Ts... ts) {
  return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

using mint = modint1000000007;

int main() {
  int n;
  cin >> n;

  auto nok = [](int x, int y, int z) -> bool {
    return (make_tuple(x, y, z) == make_tuple(0, 1, 2));
  };

  auto dp = make_vec<mint>(n, 4, 4, 4);
  // dp[i][p2][p1][nw] := i-2文字前がp2, i-1文字前がp1, i文字目がnw
  // となる文字列の個数
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < 4; k++) {
        if (nok(i, j, k) || nok(j, i, k) || nok(i, k, j))
          continue;
        dp[2][i][j][k] = 1;
      }
    }
  }

  for (int idx = 3; idx < n; idx++) {
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        for (int k = 0; k < 4; k++) {
          if (nok(i, j, k) || nok(j, i, k) || nok(i, k, j))
            continue;
          // dp[idx][i][j][k] += dp[idx-1][?][i][j]
          for (int l = 0; l < 4; l++) {
            // l, i, j, k
            if (nok(l, i, j) || nok(i, j, k) || nok(i, l, j) || nok(l, j, k) ||
                nok(l, j, i) || nok(j, i, k) || nok(l, i, k) || nok(i, k, j))
              continue;
            dp[idx][i][j][k] += dp[idx - 1][l][i][j];
          }
        }
      }
    }
  }

  mint ans = 0;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < 4; k++) {
        ans += dp[n - 1][i][j][k];
      }
    }
  }

  cout << ans.val() << endl;
}