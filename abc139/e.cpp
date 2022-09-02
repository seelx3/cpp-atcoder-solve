#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)(v.size())

int main() {
  int n;
  cin >> n;
  vector<queue<int>> a(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - 1; j++) {
      int x;
      cin >> x;
      x--;
      a[i].push(x);
    }
  }

  queue<pair<int, int>> qu;
  set<int> st;
  int cnt = 0;

  // 1 回目に行われる試合を qu に push
  for (int i = 0; i < n; i++) {
    if (st.count(i))
      continue;
    if (st.count(a[i].front()))
      continue;
    auto frnt = a[i].front();
    if (i == a[frnt].front() && !st.count(i)) {
      st.insert(i);
      st.insert(frnt);
      qu.push({i, frnt});
    }
  }

  st.clear();
  int ans = 1;

  // qu の先頭の試合後に行えるようになる試合を qu に push
  while (!qu.empty()) {
    cnt++;

    auto [u, v] = qu.front();
    qu.pop();
    a[u].pop();
    a[v].pop();

    if (st.count(u) || st.count(v)) {
      st.clear();
      ans++;
    }
    st.insert(u);
    st.insert(v);

    if (!a[u].empty()) {
      int uu = a[u].front();
      if (u == a[uu].front()) {
        qu.push({u, uu});
      }
    }

    if (!a[v].empty()) {
      int vv = a[v].front();
      if (v == a[vv].front()) {
        qu.push({v, vv});
      }
    }
  }

  if (cnt != n * (n - 1) / 2) { // すべての試合が行われたか
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }
}