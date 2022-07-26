#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(),v.end()
#define sz(v) (int)v.size()

int main(){
  int n, k;
  cin >> n >> k;
  vector<string> s(n);
  for(int i = 0; i < n; i++) {
    cin >> s[i];
  }
  int ans = 0;
  for(int i = 0; i < (1<<n); i++) {
    bitset<20> bs(i);
    vector<int> alp(26, 0);
    for(int j = 0; j < n; j++) {
      set<char> st;
      if(bs.test(j)){
        for(int k = 0; k < sz(s[j]); k++) {
          st.insert(s[j][k]);
        }
        for(auto c : st) {
          alp[c-'a']++;
        }
      }
    }
    // ちょうどkこ出現する
    int tmp = 0;
    for(int i = 0; i < 26; i++) {
      if(alp[i]==k) tmp++;
    }
    ans = max(ans, tmp);
    // cout << bs << " " << ans << endl;
  }
  cout << ans << endl;
  return 0;
}