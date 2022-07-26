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
ll dy[] = {0, 1, 0, -1};
const double PI = acos(-1.0);

/*---------------------------
---------------------------*/

int main(){
  char s1, s2, s3, t1, t2, t3;
  cin >> s1 >> s2 >> s3 >> t1 >> t2 >> t3;

  int same_cnt = 0;
  if(s1 == t1) same_cnt++;
  if(s2 == t2) same_cnt++;
  if(s3 == t3) same_cnt++;
  
  cout << ( (same_cnt!=1) ? "Yes" : "No" ) << endl;

  return 0;
}