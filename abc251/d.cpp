#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(),v.end()
#define sz(v) (int)v.size()

int main(){
  ll w;
  cin >> w;

  set<ll> st;
  vector<ll> a;

  for(int i = 1; i <= 1000000; i++) {
    if(st.count(i)) continue;
    if(sz(a) == 300) break;
    st.insert(i);
    a.push_back(i);

    ll n = sz(a);

    for(int i = 0; i < n; i++) {
      st.insert(a[i]);
    }
    
    for(int i = 0; i < n-1; i++) {
      for(int j = i+1; j < n; j++) {
        st.insert(a[i]+a[j]);
      }
    }

    for(int i = 0; i < n-2; i++) {
      for(int j = i+1; j < n-1; j++) {
        for(int k = j+1; k < n; k++) {
          st.insert(a[i]+a[j]+a[k]);
        }
      }
    }
  }

  cout << sz(a) << endl;
  for(int i = 0; i < sz(a); i++) {
    cout << a[i] << " \n"[i==sz(a)-1];
  }
}