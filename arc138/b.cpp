#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(),v.end()
#define sz(v) (int)v.size()

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++) { cin >> a[i]; }

  int sw = 0;
  int l = 0, r = n-1;
  while(true) {
    while(l < r && a[r] == sw) r--;
    if(l == r) {
      if(a[l] == sw) cout << "Yes" << endl;
      else cout << "No" << endl;
      break;
    }
    if(a[l] != sw) {
      cout << "No" << endl;
      break;
    }
    l++;
    sw ^= 1;
  }
}