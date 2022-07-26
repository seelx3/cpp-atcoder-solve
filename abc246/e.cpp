#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)
#define ALL(v) v.begin(),v.end()
#define sz(v) (ll)v.size()
const ll INF = __LONG_LONG_MAX__;
// const ll MOD = 998244353;
const ll MOD = 1000000007;
ll dx[] = {1, 1, -1, -1};
ll dy[] = {1, -1, 1, -1};
const double PI = acos(-1.0);

/*---------------------------
---------------------------*/

int main(){
  int n;
  cin >> n;
  int ax, ay, bx, by;
  cin >> ax >> ay >> bx >> by;
  ax--; ay--; bx--; by--;
  vector<string> s(n);
  for(int i = 0; i < n; i++) { cin >> s[i]; };

  // bfs
  vector<vector<ll>> d(n, vector<ll>(n, INF));
  priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
  pq.push({0, {ax, ay}});
  d[ax][ay] = 0;

  while(!pq.empty()) {
    auto tp = pq.top();
    pq.pop();
    int x = tp.second.first, y = tp.second.second;
    int dpth = tp.first;

    // cout << x << " " << y << endl;

    for(int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      while(nx >= 0 && ny >= 0 && nx<n && ny<n && d[nx][ny]>dpth+1 && s[nx][ny]=='.') {
        d[nx][ny] = dpth+1;
        pq.push({dpth+1, {nx, ny}});
        nx += dx[i];
        ny += dy[i];
      }
    }
  }

  // for(int i = 0; i < n; i++) {
  //   for(int j = 0; j < n; j++) {
  //     if(d[i][j]!=INF) cout << d[i][j] << " \n"[j==n-1];
  //     else cout << "#" << " \n"[j==n-1];
  //   }
  // }

  ll ans = d[bx][by];
  cout << (ans!=INF ? ans : -1) << endl;
}