#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)(v.size())

#define chmin(a, b) a = min(a, b)
const int inf = INT_MAX;
const int max_n = 1000000;

int main() {
  ll a, n;
  cin >> a >> n;
  vector<vector<int>> G(max_n);
  for (int i = 1; i < max_n; i++) {
    if (i * a < max_n) {
      G[i].push_back(i * a);
    }
    if (i >= 10 && i % 10 != 0) {
      string s = to_string(i);
      s = s[sz(s) - 1] + s.substr(0, sz(s) - 1);
      G[i].push_back(stoi(s));
    }
  }
  vector<int> dist(max_n, inf);
  dist[1] = 0;
  queue<int> qu;
  qu.push(1);
  while (!qu.empty()) {
    int u = qu.front();
    qu.pop();
    for (auto v : G[u]) {
      if (dist[v] != inf)
        continue;
      chmin(dist[v], dist[u] + 1);
      qu.push(v);
    }
  }
  cout << (dist[n] == inf ? -1 : dist[n]) << endl;
}