#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(),v.end()
#define sz(v) (int)v.size()

int main(){
  ll n, q;
  cin >> n >> q;
  vector<ll> pos(n), a(n);

  for(int i = 0; i < n; i++) {pos[i] = i; a[i] = i;}

  for(int i = 0; i < q; i++) {
    ll x; cin >> x;
    ll y;
    x--;

    if(pos[x] == n-1) {
      y = y = a[(pos[x]-1)%n];
      a[pos[x]] = y;
      a[(pos[x]-1)%n] = x;
      pos[x] = (pos[x] - 1) % n;
      pos[y] = (pos[y] + 1) % n;
    } else {
      y = a[(pos[x]+1)%n];
      a[pos[x]] = y;
      a[(pos[x]+1)%n] = x;
      pos[x] = (pos[x] + 1) % n;
      pos[y] = (pos[y] - 1 + n) % n;
    }
  }

  for(int i = 0; i < n; i++) {
    cout << a[i]+1 << " \n"[i==n-1];
  }

  return 0;
}