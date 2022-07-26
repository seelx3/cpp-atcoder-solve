#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(),v.end()
#define sz(v) (int)v.size()

const ll INF = __LONG_LONG_MAX__;

int main(){
  ll n;
  cin >> n;
  vector<ll> a(n);
  for(int i = 0; i < n; i++) { cin >> a[i]; }

  if(n==2) {
    cout << min(a[0], a[1]) << endl;
    return 0;
  }

  vector<ll> dp1(n, INF), dp2(n, INF);

  // 1
  dp1[0] = a[0];
  dp1[1] = a[0];
  for(int i = 2; i < n; i++) {
    dp1[i] = min(dp1[i-2]+a[i-1], dp1[i-1]+a[i]);
  }

  // 2
  dp2[0] = a[n-1];
  dp2[1] = dp2[0] + a[1];
  dp2[2] = dp2[1];
  for(int i = 3; i < n; i++) {
    dp2[i] = min(dp2[i-2]+a[i-1], dp2[i-1]+a[i]);
  }

  cout << min(dp1[n-1], dp2[n-2]) << endl;
}