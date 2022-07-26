#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(),v.end()
#define sz(v) (int)v.size()

#define INF 1001001

int x, y;

ll f(vector<int> &a) {
  if(a.empty()) return 0;
  int n = sz(a);
  if(x==y) {
    ll ret = 0;
    for(int i = 1; i <= n; i++) {
      ret += i;
    }
    return ret;
  }
  // for(int i = 0; i < n; i++) {
  //   cout << a[i] << " \n"[i==n-1];
  // }
  vector<int> m, M;
  for(int i = 0; i < n; i++) {
    if(a[i]==y) m.push_back(i);
    if(a[i]==x) M.push_back(i);
  }
  m.push_back(INF);
  M.push_back(INF);
  int i_m = 0, i_M = 0;
  ll ans = 0;
  while(m[i_m]!=INF && M[i_M]!=INF) {
    // cout << m[i_m] << " " << M[i_M] << endl;
    int r = max(m[i_m], M[i_M]);
    ans += n - r;

    if(m[i_m] < M[i_M]) i_m++;
    else i_M++;
  }
  // cout << ans << endl;
  for(int i = 0; i < n; i++) {
    if(a[i]!=x && a[i]!=y) {
      int mn_l = *lower_bound(ALL(m), i);
      int mx_l = *lower_bound(ALL(M), i);
      if(mn_l == INF || mx_l == INF) continue;
      int r = max(mn_l, mx_l);
      ans += n - r;
    }
  }
  return ans;
}

int main(){
  int n;
  cin >> n >> x >> y;
  vector<int> a(n);
  for(int i = 0; i < n; i++) { cin >> a[i]; };
  vector<vector<int>> v(n);
  int now = 0;
  for(int i = 0; i < n; i++) {
    if(a[i] > x || a[i] < y) now++;
    else {
      v[now].push_back(a[i]);
    }
  }
  ll ans = 0;
  for(int i = 0; i < n; i++) {
    if(v[i].empty()) continue;
    ans += f(v[i]);
  }
  cout << ans << endl;
}