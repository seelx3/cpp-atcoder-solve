#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)(v.size())

int main() {
  int m;
  cin >> m;
  vector<vector<int>> G(9);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  string start = "";
  set<char> st = {'0', '1', '2', '3', '4', '5', '6', '7', '8'};
  for (int i = 0; i < 8; i++) {
    char c;
    cin >> c;
    c--;
    start.push_back(c);
    st.erase(c);
  }
  start.push_back(*st.begin());
  queue<string> qu;
  qu.push(start);
  map<string, int> d = {{start, 0}};

  while (!qu.empty()) {
    string now = qu.front();
#ifdef DEBUG
    cout << "now: " << now << endl;
#endif
    qu.pop();
    int u = now[sz(now) - 1] - '0';
#ifdef DEBUG
    cout << "u  : " << u << endl;
#endif
    for (auto v : G[u]) {
      string nx = now;
      // nx の '0'+u と '0'+v を swap
      for (auto& c : nx) {
        if (c == ('0' + v))
          c = '0' + u;
      }
      nx[sz(nx) - 1] = '0' + v;
#ifdef DEBUG
      cout << "nx : " << nx << endl;
#endif
      if (d.find(nx) == d.end()) {
        d[nx] = d[now] + 1;
        qu.push(nx);
      }
    }
  }

  string goal = "012345678";
  cout << (d.find(goal) == d.end() ? -1 : d[goal]) << endl;
}