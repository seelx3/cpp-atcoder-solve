#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(),v.end()
#define sz(v) (int)v.size()

int main(){
  string s;
  cin >> s;
  set<char> st;
  bool f1 = false, f2 = false;
  for(int i = 0; i < sz(s); i++) {
    if(s[i] >= 'a' && s[i] <= 'z') f1 = true;
    if(s[i] >= 'A' && s[i] <= 'Z') f2 = true;
    st.insert(s[i]);
  }
  if(f1 && f2 && sz(s)==sz(st)) cout << "Yes\n";
  else cout << "No\n";
  return 0;
}