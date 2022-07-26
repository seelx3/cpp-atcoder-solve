#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(),v.end()
#define sz(v) (int)v.size()

int main(){
  ll n;
  cin >> n;

  ll ans = 0, point = -1;
  string s;

  ll pnt;
  set<string> st;

  for(int i = 0; i < n; i++) {
    cin >> s >> pnt;
    if(st.count(s)) continue;
    st.insert(s);
    if(point < pnt) {
      point = pnt;
      ans = i;
    }
  }

  cout << ans+1 << endl;
}