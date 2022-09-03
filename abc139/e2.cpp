#ifndef INCLUDED_MAIN
#define INCLUDED_MAIN

#include __FILE__

using Graph = vector<vector<int>>;

int maxdist(Graph& G, int start) {
  int n = sz(G);
  vector<int> dist(n, -1);
  queue<int> qu;
  dist[start] = 0;
  qu.push(start);

  int ret = -1;

  while (!qu.empty()) {
    int u = qu.front();
    qu.pop();
    for (auto v : G[u]) {
      if (dist[v] != -1)
        continue;
      dist[v] = dist[u] + 1;
      ret = max(ret, dist[v]);
      qu.push(v);
    }
  }
  return ret;
}

int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> id;
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      id.push_back({i, j});
    }
  }

  Graph G(sz(id));
  for (int i = 0; i < n; i++) {
    int pre;
    cin >> pre;
    pre--;
    for (int j = 1; j < n - 1; j++) {
      int nx;
      cin >> nx;
      nx--;
      pair<int, int> u = {i, pre}, v = {i, nx};
      if (u.first > u.second)
        swap(u.first, u.second);
      if (v.first > v.second)
        swap(v.first, v.second);
      // (i, u) -> (i, v)
      int u_id = lower_bound(ALL(id), u) - id.begin();
      int v_id = lower_bound(ALL(id), v) - id.begin();
      G[u_id].push_back(v_id);
    }
  }

  for (int i = 0; i < sz(id); i++) {
    cout << "{" << id[i].first << "," << id[i].second << "}"
         << " \n"[i == sz(id) - 1];
  }

  vector<int> ts = tsort(G);

  for (int i = 0; i < sz(ts); i++) {
    cout << i << " : ";
    for (int j = 0; j < sz(G[i]); j++) {
      cout << G[i][j] << " \n"[j == sz(G[i]) - 1];
    }
  }

  if (sz(ts) != sz(G)) {
    cout << -1 << endl;
  } else {
    // TODO
  }
}

/*-----------------------------------------------------------
-----------------------------------------------------------*/

#else // INCLUDED_MAIN

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

#endif // INCLUDED_MAIN