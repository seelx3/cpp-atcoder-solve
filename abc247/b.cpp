#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(),v.end()
#define sz(v) (int)v.size()

int main(){
  int n;
  cin >> n;
  map<string, int> mp;
  vector<string> s(n), t(n);
  for(int i = 0; i < n; i++) {
    cin >> s[i] >> t[i]; 
    mp[s[i]]++;
    mp[t[i]]++;
  } 
  bool ok = true;
  for(int i = 0; i < n; i++) {
    if(mp[s[i]] > 1 && mp[t[i]] > 1) {
      if(mp[s[i]]==2 && s[i]==t[i]) continue;
      ok = false;
    }
  }
  cout << (ok ? "Yes" : "No") << endl;
}