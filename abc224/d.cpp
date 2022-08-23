#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)(v.size())

int main() {
  vector<vector<int>> G(9);
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  string start = "";
  for (int i = 0; i < 8; i++) {
    int p;
    cin >> p;
    p--;
    start.push_back('0' + p);
  }

  map<string, int> d;
  d[start] = 0;

  set<int> vs = {0, 1, 2, 3, 4, 5, 6, 7, 8};

  queue<string> qu;
  qu.push(start);

  while (!qu.empty()) {
    string now = qu.front();
#ifdef DEBUG
    cout << now << endl;
#endif
    qu.pop();
    set<int> t = vs;
    for (auto c : now) {
      t.erase(c - '0');
    }
    int u = *t.begin();
#ifdef DEBUG
    cout << "u : " << u << endl;
#endif
    for (auto v : G[u]) {
      string nx = now;
      for (int i = 0; i < 8; i++) {
        if (nx[i] == '0' + v)
          nx[i] = '0' + u;
      }
#ifdef DEBUG
      cout << "v : " << v << ", nx : " << nx << endl;
#endif
      if (d.find(nx) == d.end()) {
        d[nx] = d[now] + 1;
        qu.push(nx);
      }
    }
  }

  string dist = "01234567";
  cout << (d.find(dist) == d.end() ? -1 : d[dist]) << endl;
}