#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(),v.end()
#define sz(v) (int)v.size()

int main(){
  int n;
  cin >> n;
  vector<string> s(n);
  for(int i = 0; i < n; i++) { cin >> s[i]; }

  int ans = __INT_MAX__;

  for(int fst = 0; fst < 10; fst++) {
    multiset<int> st;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < 10; j++) {
        if(s[i][j] == '0'+fst) {
          st.insert(j);
        }
      }
    }
    int tmp = 0;
    for(int i = 0; i < 10; i++) {
      if(!st.count(i)) continue;
      tmp = max(tmp, int(i+(st.count(i)-1)*10));
    }
    ans = min(ans, tmp);
  }
  cout << ans << endl;
}