#include <atcoder/all>
#include <bits/stdc++.h>
using namespace atcoder;
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)(v.size())

using P = pair<ll, ll>;
using mint = modint998244353;

int main() {
  ll n, m;
  cin >> n >> m;
  vector<P> dxy(3);
  for (int i = 0; i < 3; i++) {
    cin >> dxy[i].first >> dxy[i].second;
  }
  set<P> obst;
  for (int i = 0; i < m; i++) {
    ll x, y;
    cin >> x >> y;
    obst.insert({x, y});
  }

  // dp[i][x][y] = i回ワープしたときに座標(x, y)にいるような移動経路
  map<P, mint> dp;
  dp[{0, 0}] = 1;
  for (int i = 1; i <= n; i++) {
    map<P, mint> nxdp;
    for (auto cur : dp) {
      for (auto d : dxy) {
        ll nxx = cur.first.first + d.first;
        ll nxy = cur.first.second + d.second;
        if (obst.find({nxx, nxy}) == obst.end())
          nxdp[{nxx, nxy}] += dp[cur.first];
      }
    }
    dp = nxdp;
  }

  mint ans = 0;
  for (auto it : dp) {
    ans += it.second;
  }

  cout << ans.val() << endl;
}