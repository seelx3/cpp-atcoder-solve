#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)
#define ALL(v) v.begin(),v.end()
#define sz(v) (ll)v.size()
const ll INF = 1e18;
// const ll MOD = 998244353;
const ll MOD = 1000000007;
ll dx[] = {1, 0, -1, 0};
ll dy[] = {0, 1, 0, -1};
const double PI = acos(-1.0);

/*---------------------------

---------------------------*/

int main(){
  ll x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;

  vector<pair<int, int>> d = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};

  set<pair<int, int>> st1, st2;

  for(int i = 0; i < 8; i++) {
    st1.insert({x1 + d[i].first, y1 + d[i].second});
  }
  for(int i = 0; i < 8; i++) {
    st2.insert({x2 + d[i].first, y2 + d[i].second});
  }

  bool ok = false;

  for(auto p : st1) {
    if(st2.count(p)) ok = true;
  }

  cout << (ok ? "Yes" : "No") << endl;

}