#include <atcoder/all>
#include <bits/stdc++.h>
using namespace atcoder;
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)(v.size())

using mint = modint998244353;

int main() {
  ll n, m, k;
  cin >> n >> m >> k;
  vector<ll> a(m);
  for (int i = 0; i < m; i++) {
    cin >> a[i];
    a[i]--;
  }
  vector<vector<int>> G(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  // edge_used[{a, b}] : 頂点aと頂点b(ただしa<b)を結ぶ辺を通った回数
  map<pair<int, int>, int> edge_used;

  function<bool(int, int, int, int)> dfs = [&](int start, int goal, int u,
                                               int par) -> bool {
    bool found = (u == goal);
    for (auto v : G[u]) {
      if (v == par)
        continue;
      found = found || dfs(start, goal, v, u);
    }
    if (found && u != start) {
      if (u < par)
        edge_used[{u, par}]++;
      else
        edge_used[{par, u}]++;
    }
    return found;
  };

  for (int i = 0; i < m - 1; i++) {
    int start = a[i];
    int goal = a[i + 1];
    dfs(start, goal, start, -1);
  }

#ifdef DEBUG
  for (auto [edge, count] : edge_used) {
    cout << edge.first << ", " << edge.second << " = " << count << endl;
  }
  cout << endl;
#endif

  vector<ll> edge_use_cnt;
  ll sum_cnt = 0;
  for (auto [_, count] : edge_used) {
    edge_use_cnt.push_back(count);
    sum_cnt += count;
  }

  mint ans = 1;
  for (int i = 0; i < (n - 1) - sz(edge_use_cnt); i++) {
    ans *= 2;
  }

  // r + b = sum_cnt
  // b + b + k = sum_cnt
  if ((sum_cnt - k) % 2 != 0) {
    cout << 0 << endl;
    return 0;
  }
  ll b = (sum_cnt - k) / 2;

#ifdef DEBUG
  cout << "b = " << b << endl;
#endif

  // edge_use_cnt からいくつか選択したとき、和を b にできるものの個数
  // b <= 10^5

  // (edge_use_cnt を i までみたとき、)和がjとなる個数
  map<int, mint> su_cnt = {{0, 1}};
  for (int i = 0; i < sz(edge_use_cnt); i++) {
    map<int, mint> nx_su_cnt;
    for (auto [su, cnt] : su_cnt) {
      if (su + edge_use_cnt[i] > b)
        continue;
      nx_su_cnt[su + edge_use_cnt[i]] += cnt;
    }
    for (auto [su, cnt] : su_cnt) {
      nx_su_cnt[su] += cnt;
    }
    su_cnt = nx_su_cnt;
#ifdef DEBUG
    cout << "i = " << i << endl;
    for (auto [su, cnt] : su_cnt) {
      cout << "su_cnt[" << su << "] = " << cnt.val() << endl;
    }
#endif
  }

  ans *= su_cnt[b];
  cout << ans.val() << endl;
}