#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(),v.end()
#define sz(v) (int)v.size()

int main(){
  ll n;
  cin >> n;
  vector<ll> a(n);
  for(int i = 0; i < n; i++) { cin >> a[i]; }
  reverse(ALL(a));

  ll sum = 0;
  ll cnt = 0;
  for(int i = 0; i < n; i++) {
    sum += a[i];
    if(sum <= 3) cnt++;
    else break;
  }
  cout << n - cnt << endl;
}