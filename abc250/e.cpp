#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(),v.end()
#define sz(v) (int)v.size()

int main(){
  ll n;
  cin >> n;
  vector<ll> a(n), b(n);
  for(int i = 0; i < n; i++) { cin >> a[i]; }
  for(int i = 0; i < n; i++) { cin >> b[i]; }
  ll q;
  cin >> q;

  vector<pair<ll, ll>> I(n);

  set<ll> st_a, st_b, st_ab;

  ll r = 0, l;

  for(int i = 0; i < n; i++) {
    if(st_ab.count(a[i])) {
      I[i] = I[i-1];
      continue;
    }
    if(st_b.count(a[i])) { // a[i] in b
      st_b.erase(a[i]);
      st_ab.insert(a[i]);
    } else {
      st_a.insert(a[i]);
    }
    while(r < n && sz(st_a) && sz(st_b)==0) {
      if(st_ab.count(b[r])) ;
      else if(st_a.count(b[r])) {
        st_a.erase(b[r]);
        st_ab.insert(b[r]);
      } else {
        st_b.insert(b[r]);
      }
      r++;
    }
    if(sz(st_a)) I[i] = {n, n};
    else {
      l = r-1;
      while(r < n && st_ab.count(b[r])) r++;
      I[i] = {l, r};
    }
  }

  for(int i = 0; i < q; i++) {
    ll x, y;
    cin >> x >> y;
    x--; y--;
    cout << (y >= I[x].first && y < I[x].second ? "Yes" : "No") << endl;
  }

  return 0;
}