#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(),v.end()
#define sz(v) (int)v.size()

int main(){
  int n;
  cin >> n;
  vector<ll> a(n);
  map<ll, ll> mp;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    mp[a[i]]++;
  }
  ll ans = 0;
  for(auto it : mp) {
    int m = it.first;
    int tmp = 0;
    for(int i = 1; i*i <= m; i++) {
      if(m % i == 0) {
        if(!(mp.count(i) && mp.count(m/i))) continue;
        if(i==m/i) ans += (mp[i]*mp[it.first/i]) * it.second;
        else ans += (mp[i]*mp[it.first/i]*2) * it.second;
      }
    }
  }
  cout << ans << endl;
}