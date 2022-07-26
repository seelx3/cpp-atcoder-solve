#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(),v.end()
#define sz(v) (int)v.size()

int main(){
  ll n;
  cin >> n;
  vector<ll> v(n);
  for(int i = 0; i < n; i++) {cin >> v[i];}

  set<ll> a, b, ab;
  multiset<ll> b_mul, ab_mul;
  a.insert(v[0]);
  for(int i = 2; i < n; i++) {
    b.insert(v[i]);
    b_mul.insert(v[i]);
  }
  if(b.count(v[0])) ab.insert(v[0]), ab_mul.insert(v[0]);

  ll ans = 0;
  for(int i = 1; i < n-1; i++) {
    ans += (sz(a) - a.count(v[i])) * (sz(b) - b.count(v[i])) - (sz(ab) - ab.count(v[i]));

    a.insert(v[i]);
    b_mul.erase(b_mul.find(v[i+1]));
    if(!b_mul.count(v[i+1])) b.erase(v[i+1]);
    if(a.count(v[i]) && b.count(v[i])) ab.insert(v[i]);
    else ab.erase(v[i]);
    if(a.count(v[i+1]) && b.count(v[i+1])) ab.insert(v[i+1]);
    else ab.erase(v[i+1]);
  }

  cout << ans << endl;
}