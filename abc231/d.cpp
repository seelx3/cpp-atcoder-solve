#include <atcoder/all>
#include <bits/stdc++.h>
using namespace atcoder;
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)(v.size())

int main() {
  ll n, m;
  cin >> n >> m;
  vector<vector<int>> G(n);
  dsu uf(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    G[a].push_back(b);
    G[b].push_back(a);
    uf.merge(a, b);
  }
  bool ok = true;

  // 各連結成分について
  // 各頂点から出ている辺の個数が2以下
  // 連結成分を後世する辺の個数は、(その連結成分の頂点数)-1
  set<int> roots;
  for (int i = 0; i < n; i++) {
    roots.insert(uf.leader(i));
    if (sz(G[i]) > 2)
      ok = false;
  }
  map<int, int> edgecnt;
  for (int i = 0; i < n; i++) {
    edgecnt[uf.leader(i)] += sz(G[i]);
  }
  for (auto rt : roots) {
#ifdef DEBUG
    cout << rt << " : " << edgecnt[rt] << " " << uf.size(rt) << endl;
#endif
    if (edgecnt[rt] / 2 != uf.size(rt) - 1)
      ok = false;
  }

  cout << (ok ? "Yes" : "No") << endl;
}