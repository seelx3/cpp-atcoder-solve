#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)v.size()

struct jumper {
  ll x;
  ll y;
  ll p;
};

int main() {
  ll n;
  cin >> n;
  vector<jumper> jump(n);
  for (int i = 0; i < n; i++) {
    ll x, y, p;
    cin >> x >> y >> p;
    jump[i] = {x, y, p};
  }
  vector<vector<pair<ll, ll>>> G(n);
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      ll dist = abs(jump[i].x - jump[j].x) + abs(jump[i].y - jump[j].y);
      G[i].push_back({j, dist});
      G[j].push_back({i, dist});
    }
  }

  vector<bool> seen(n, false);

  function<void(ll, ll)> dfs = [&](ll u, ll trcnt) {
    if (seen[u])
      return;
    seen[u] = true;
    for (auto v : G[u]) {
      if (v.second <= jump[u].p * trcnt)
        dfs(v.first, trcnt);
    }
  };

  auto jumpable = [&](ll traincnt) {
    bool ok = false;
    for (int u = 0; u < n; u++) {
      fill(ALL(seen), false);
      dfs(u, traincnt);
      bool alok = true;
      for (auto sn : seen)
        if (!sn)
          alok = false;
      if (alok)
        ok = true;
    }
    return ok;
  };

  ll l = 0, r = 10001001001, mid;
  while (l + 1 < r) {
    mid = (l + r) / 2;
    // 訓練回数がmidのとき全てのジャンプ台を移動できるか？
    if (jumpable(mid))
      r = mid;
    else
      l = mid;
  }

  cout << r << endl;
}