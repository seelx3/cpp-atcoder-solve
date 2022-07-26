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
  vector<string> s(n);
  for(int i = 0; i < n; i++) {
    cin >> s[i];
  }

  for(int i = 0; i < n; i++) {
    for(int j = 0; j <= n-6; j++) {
      int cnt = 0;
      for(int k = 0; k < 6; k++) {
        if(s[i][j+k] == '#') cnt++;
      }
      if(cnt >= 4) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }

  for(int i = 0; i <= n-6; i++) {
    for(int j = 0; j < n; j++) {
      int cnt = 0;
      for(int k = 0; k < 6; k++) {
        if(s[i+k][j] == '#') cnt++;
      }
      if(cnt >= 4) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }

  for(int i = 0; i <= n-6; i++) {
    for(int j = 0; j <= n-6; j++) {
      int cnt_a = 0, cnt_b = 0;
      for(int k = 0; k < 6; k++) {
        if(s[i+k][j+k] == '#') cnt_a++;
        if(s[i+k][j+5-k] == '#') cnt_b++;
      } 
      if(cnt_a >= 4 || cnt_b >= 4) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  
  cout << "No" << endl;
}