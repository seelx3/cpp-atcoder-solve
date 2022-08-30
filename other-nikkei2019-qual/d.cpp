#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)(v.size())

vector<int> tsort(vector<vector<int>> G) {
  vector<int> in(sz(G)); // 入次数
  for (int i = 0; i < sz(G); i++) {
    for (int j = 0; j < sz(G[i]); j++)
      in[G[i][j]]++;
  }
  queue<int> qu;
  for (int i = 0; i < sz(G); i++) {
    if (in[i] == 0)
      qu.push(i);
  }
  vector<int> ret;
  while (!qu.empty()) {
    int u = qu.front();
    qu.pop();
    ret.push_back(u);
    for (int i = 0; i < sz(G[u]); i++) {
      int v = G[u][i];
      in[v]--;
      if (in[v] == 0)
        qu.push(v);
    }
  }
  return ret;
}

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<int>> G(N);
  vector<vector<int>> pars(N);
  for (int i = 0; i < N - 1 + M; i++) {
    int s, t;
    cin >> s >> t;
    s--;
    t--;
    G[s].push_back(t);
    pars[t].push_back(s);
  }
  vector<int> tpo = tsort(G);
  vector<int> d(N);
  for (int i = 0; i < N; i++) {
    d[tpo[i]] = i;
  }
  for (int i = 0; i < N; i++) {
    int ans = -1;
    int mx = -1;
    for (auto p : pars[i]) {
      if (mx < d[p]) {
        mx = d[p];
        ans = p;
      }
    }
    cout << ans + 1 << endl;
  }

  return 0;
}