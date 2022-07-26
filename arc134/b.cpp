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
17
snwfpfwipeusiwkzo
x        x
 x   x
  xx

effwpnwipsusiwkzo
---------------------------*/

int main(){
  ll n;
  string s;
  cin >> n >> s;

  vector<vector<ll>> dic(26);
  for(int i = 0; i < 26; i++) dic[i].push_back(-INF);
  for(int i = 0; i < n; i++){
    dic[s[i]-'a'].push_back(i);
  }
  for(int i = 0; i < 26; i++) dic[i].push_back(INF);

  int le = 0, ri = n-1;
  string ans = s;
  for(int i = 0; i < n; i++){
    if(le >= ri) break;
    // 最も小さい文字 ri以下の一番右
    for(int ch = 0; ch < ans[i]-'a'; ch++){
      auto itr = lower_bound(ALL(dic[ch]), ri+1);
      itr--;
      ll pos = *itr;
      if(pos >= le){
        swap(ans[i], ans[pos]);
        ri = pos-1;
        break;
      }
    }
    le = i+1;
  }

  cout << ans << endl;
}