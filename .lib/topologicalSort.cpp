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
  int V, E;
  cin >> V >> E;
  vector<vector<int>> G(V);
  for (int i = 0; i < E; i++) {
    int s, t;
    cin >> s >> t;
    G[s].push_back(t);
  }
  vector<int> ans = tsort(G);
  for (int i = 0; i < sz(ans); i++)
    cout << ans[i] << " \n"[i == sz(ans) - 1];

  return 0;
}

/*
10 9
0 1
1 3
3 2
3 4
4 5
5 6
6 7
7 8
8 9
*/