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
  int n, x;
  cin >> n >> x;
  vector<bool> visit(10001);
  visit[0] = true;
  for(int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    for(int j = 10000; j >= 0; j--) {
      if(visit[j]) {
        visit[j+a] = true;
        visit[j+b] = true; 
        visit[j] = false;
      }
    }
  }
  cout << (visit[x] ? "Yes" : "No" ) << "\n";
}