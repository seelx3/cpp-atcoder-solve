#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)v.size()

int main() {
  ll N, Q, X;
  cin >> N >> Q >> X;
  vector<ll> w(2 * N);
  for (int i = 0; i < N; i++) {
    cin >> w[i];
    w[i + N] = w[i];
  }
  vector<ll> sum(2 * N);
  for (int i = 0; i < 2 * N; i++) {
    if (i >= 1)
      sum[i] += sum[i - 1];
    sum[i] += w[i];
  }

#ifdef DEBUG
  for (int i = 0; i < 2 * N; i++)
    cout << i << " \n"[i == 2 * N - 1];
  for (int i = 0; i < 2 * N; i++)
    cout << w[i] << " \n"[i == 2 * N - 1];
  for (int i = 0; i < 2 * N; i++)
    cout << sum[i] << " \n"[i == 2 * N - 1];
#endif

  // i個目のじゃがいもからスタートしたときの箱に入るじゃがいもの個数
  vector<ll> cnt(N);

  // i番目のじゃがいもからスタートしたとき、次のスタートのじゃがいも番号
  vector<ll> to(N, -1);

  int start = 0;
  while (to[start] == -1) {
    ll nw = (start == 0 ? 0 : sum[start - 1]);
    ll xx = X % sum[N - 1];
    int nx;
    if (xx == 0)
      nx = start;
    else
      nx = lower_bound(ALL(sum), nw + xx) - sum.begin() + 1;
    to[start] = nx % N;
    cnt[start] = N * (X / sum[N - 1]) + nx - start;
    start = nx % N;
  }

#ifdef DEBUG
  for (int i = 0; i < N; i++) {
    cout << i << " : to = " << to[i] << ", cnt = " << cnt[i] << endl;
  }
#endif

  int K = 1;
  while ((1LL << K) < 1000000000000)
    K++;

  vector<vector<int>> doubling(K, vector<int>(N, -1));
  // doubling[k][i] : iから2^k先の頂点
  for (int i = 0; i < N; i++) {
    doubling[0][i] = to[i];
  }
  for (int k = 1; k < K; k++) {
    for (int i = 0; i < N; i++) {
      if (doubling[k - 1][i] == -1)
        continue;
      doubling[k][i] = doubling[k - 1][doubling[k - 1][i]];
    }
  }

  while (Q--) {
    ll k;
    cin >> k;
    k--;
    int now = 0;
    for (int i = 0; i < K; i++) {
      if ((k >> i) & 1) {
        now = doubling[i][now];
      }
    }
    cout << cnt[now] << endl;
  }
}