#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(),v.end()
#define sz(v) (int)v.size()

int main(){
  ll n, w;
  cin >> n >> w;
  vector<ll> a(n);
  for(int i = 0; i < n; i++) { cin >> a[i]; }

  set<ll> st;
  for(int i = 0; i < n; i++) {
    if(a[i] <= w) st.insert(a[i]);
  }
  
  for(int i = 0; i < n-1; i++) {
    for(int j = i+1; j < n; j++) {
      if(a[i]+a[j] <= w) st.insert(a[i]+a[j]);
    }
  }

  for(int i = 0; i < n-2; i++) {
    for(int j = i+1; j < n-1; j++) {
      for(int k = j+1; k < n; k++) {
        if(a[i]+a[j]+a[k] <= w) st.insert(a[i]+a[j]+a[k]);
      }
    }
  }

  cout << sz(st) << endl;
}