#include <atcoder/all>
#include <bits/stdc++.h>
using namespace atcoder;
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)(v.size())

using mint = modint998244353;
const ll MOD = 998244353;

int modpow(int x, int n) { return pow_mod(x, n, MOD); }

int main() {
  ll N, D;
  cin >> N >> D;

  vector<mint> cnt(2000100);
  for (int l = (D + 1) / 2; l <= D; l++) {
    int s = D - l;
    cnt[l] += cnt[l - 1];
    if (l == s) {
      cnt[l] += modpow(2, D - 2);
    } else if (l > s && l != D) {
      cnt[l] += modpow(2, D - 1);
    } else { // l == D
      cnt[l] += modpow(2, D);
    }
  }

  mint ans = 0;
  for (int depth = 0; depth <= N; depth++) {
    if ((N - depth) * 2 < D)
      break;
    mint part_ans = cnt[min(N - 1 - depth, D)];
#ifdef DEBUG
    cout << depth << " : " << min(N - depth, D) << " " << part_ans.val()
         << endl;
#endif
    part_ans *= modpow(2, depth);
    ans += part_ans;
  }
  ans *= 2;
  cout << ans.val() << endl;
}