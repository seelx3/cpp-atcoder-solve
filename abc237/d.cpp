#include <bits/stdc++.h>
using namespace std;
#define ll long long
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
  ll n;
  string s;
  cin >> n >> s;
  deque<ll> ans;
  char op = 'R';
  for(int i = n; i >= 0; i--) {
    if(op == 'R') ans.push_front(i);
    else ans.push_back(i);
    if(i!=0) op = s[i-1];
    // cout << op << endl;
  }
  for(int i = 0; i <= n; i++) {
    cout << ans.at(i) << " \n"[i==n];
  } 
}