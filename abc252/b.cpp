#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(),v.end()
#define sz(v) (int)v.size()

int main(){
  int n, k;
  cin >> n >> k;
  vector<int> a(n), b(k);
  int mx = 0;
  for(int i = 0; i < n; i++) {cin >> a[i]; mx = max(mx, a[i]);}
  for(int i = 0; i < k; i++) {cin >> b[i]; b[i]--;}
  
  bool ans = false;
  for(int i = 0; i < k; i++) {
    if(a[b[i]] == mx) ans = true;
  }
  
  cout << (ans ? "Yes" : "No") << endl;
}