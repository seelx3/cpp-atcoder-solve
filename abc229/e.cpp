#include <atcoder/all>
#include <bits/stdc++.h>
using namespace atcoder;
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)(v.size())

using Graph = vector<vector<int>>;

int main() {
  ll n, m;
  cin >> n >> m;
  Graph G(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  vector<ll> ans;
  set<ll> st;
  ll conn = 0;
  dsu uf(n);
  for (int i = n - 1; i > 0; i--) {
    st.insert(i);
    conn++;
    for (auto v : G[i]) {
      if (st.count(v) && !uf.same(i, v)) {
        uf.merge(i, v);
        conn--;
      }
    }
    ans.push_back(conn);
  }
  reverse(ALL(ans));
  for (auto conn : ans) {
    cout << conn << endl;
  }
  cout << 0 << endl;
}