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
  int n; string s;
  cin >> n >> s;

  string t = "";
  for(int i = 0; i < n; i++) {
    if(s[i] == 'A') {
      t.push_back('B');
      t.push_back('B');
    } else if(s[i] == 'B') t.push_back('B');
    else t.push_back('C');
  }
  string ans = "";
  for(int i = 0; i < sz(t); i++) {
    if(i+1 < sz(t) && t[i]=='B' && t[i+1]=='B') {
      ans.push_back('A');
      i++;
    } else {
      ans.push_back(t[i]);
    }
  }

  cout << ans << endl;
}