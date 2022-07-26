#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(),v.end()
#define sz(v) (int)v.size()

int main(){
  int n;
  cin >> n;
  vector<vector<ll>> a(n);
  a[0].push_back(1);
  for(int i = 1; i < n; i++) {
    a[i].push_back(1);
    for(int j = 0; j < i-1; j++) {
      a[i].push_back(a[i-1][j]+a[i-1][j+1]);
    }
    a[i].push_back(1);
  }

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < i+1; j++) {
      cout << a[i][j] << " \n"[j==i];
    }
  }
}