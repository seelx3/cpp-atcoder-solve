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
ll dx[] = {1, 0, -1, 0};
ll dy[] = {0, -1, 0, 1};
const double PI = acos(-1.0);

/*---------------------------
---------------------------*/

int main(){
  ll n;
  string t;
  cin >> n >> t;

  ll x = 0, y = 0;
  ll direction = 0;

  for(int i = 0; i < n; i++) {
    if(t[i] == 'S') {
      x += dx[direction];
      y += dy[direction];
    } else {
      direction = (direction+1) % 4;
    }
  }

  cout << x << " " << y << endl;
}