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
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++) { cin >> a[i]; };

  stack<pair<int, int>> stk;
  int ballCnt = 0;
  for(int i = 0; i < n; i++) {
    if(stk.empty()) {
      stk.push({a[i], 1});
      ballCnt++;
      cout << ballCnt << endl;
      continue;
    } 
    if(stk.top().first == a[i]) {
      stk.top().second++;
      ballCnt++;
    } else {
      stk.push({a[i], 1});
      ballCnt++;
    }
    if(stk.top().first == stk.top().second){
      ballCnt -= stk.top().second;
      stk.pop();
    }
    // cout << "{" << stk.top().first << ", " << stk.top().second << " }\n";
    cout << ballCnt << endl;
  }
}