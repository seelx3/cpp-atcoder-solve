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
  string s;
  cin >> s;
  ll top_a = 0, back_a = 0;
  for(int i = 0; i < sz(s); i++) {
    if(s[i]=='a') top_a++;
    else break;
  }
  for(int i = sz(s)-1; i >= 0; i--) {
    if(s[i]=='a') back_a++;
    else break;
  }
  if(top_a > back_a) {
    cout << "No" << endl;
    return 0;
  }
  ll n = sz(s);
  ll dif = back_a - top_a;
  for(int i = n-dif-1; i > (n-dif)/2-1; i--) {
    if(s[i]!=s[n-dif-1-i]) {
      cout << "No" << endl;
      return 0;
    }
  } 
  cout << "Yes" << endl;
}