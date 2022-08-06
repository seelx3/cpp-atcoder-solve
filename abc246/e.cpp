#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)v.size()

#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)

const ll inf = 100100100100;

ll dx[] = {1, -1, -1, 1};
ll dy[] = {1, 1, -1, -1};

int main() {
  ll n;
  cin >> n;
  ll ax, ay, bx, by;
  cin >> ax >> ay >> bx >> by;
  ax--;
  ay--;
  bx--;
  by--;

  vector<string> s(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }

  vector<vector<vector<ll>>> d(n, vector<vector<ll>>(n, vector<ll>(4, inf)));
  // d[x][y][dir] := (x, y)にdir方向から入ってきたときの移動回数の最小値
  // dir : 0 1 2 3

  deque<pair<pair<ll, ll>, ll>> dq;
  for (int dir = 0; dir < 4; dir++) {
    d[ax][ay][dir] = 1;
    dq.push_front({{ax, ay}, dir});
  }

  while (!dq.empty()) {
    auto tp = dq.front();
    dq.pop_front();
    ll xx = tp.first.first;
    ll yy = tp.first.second;
    // cout << xx << ", " << yy << endl;
    int di = tp.second;
    for (int dir = 0; dir < 4; dir++) {
      // cout << "hello" << endl;
      if (xx + dx[dir] < 0 || xx + dx[dir] >= n || yy + dy[dir] < 0 ||
          yy + dy[dir] >= n)
        continue;
      ll nx = xx + dx[dir];
      ll ny = yy + dy[dir];
      if (s[nx][ny] == '#')
        continue;
      if (dir == di) {
        if (d[nx][ny][dir] <= d[xx][yy][di])
          continue;
        chmin(d[nx][ny][dir], d[xx][yy][di]);
        dq.push_front({{nx, ny}, dir});
      } else {
        if (d[nx][ny][dir] <= d[xx][yy][di] + 1)
          continue;
        chmin(d[nx][ny][dir], d[xx][yy][di] + 1);
        dq.push_back({{nx, ny}, dir});
      }
    }
  }

  for (int dir = 0; dir < 4; dir++) {
    d[ax][ay][dir] = 0;
  }

  ll ans = inf;
  for (int i = 0; i < 4; i++) {
    chmin(ans, d[bx][by][i]);
  }

  cout << (ans == inf ? -1 : ans) << endl;

  /////// debug
  // for (int i = 0; i < n; i++) {
  //   for (int j = 0; j < n; j++) {
  //     if (s[i][j] == '#') {
  //       cout << "#";
  //       continue;
  //     }
  //     ll mi = inf;
  //     for (int k = 0; k < 4; k++) {
  //       chmin(mi, d[i][j][k]);
  //     }
  //     if (mi == inf)
  //       cout << ".";
  //     else
  //       cout << mi;
  //   }
  //   cout << endl;
  // }
}