#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(),v.end()
#define sz(v) (int)v.size()

const int INF = 100100100;

int main(){
  int n, k;
  cin >> n >> k;
  vector<ll> a(n);
  set<ll> st;
  for(int i = 0; i < n; i++) { cin >> a[i]; st.insert(a[i]); }

  ll s = 0;
  for(int i = 0; i < k; i++) { s += a[i]; }

  vector<ll> b;
  for(auto it : st) {
    b.push_back(it);
  }

  for(int i = 0; i < n; i++) {
    a[i] = lower_bound(ALL(b), a[i]) - b.begin();
  }

  const int st_size = st.size();

  // for(int i = 0; i < n; i++) { cout << a[i] << " \n"[i==n-1]; }

  // pos[a[i]]: いつa[i]+1よりも大きい値がk番目以降で出てくるか？

  /**
   * 6 3
   * 1 2 3 1 2 4
   */

  vector<int> pos(st_size, INF);
  for(int i = k; i < n; i++) {
    pos[a[i]] = min(pos[a[i]], i);
  }

  for(int i = 0; i < st_size-1; i++) {
    pos[i] = pos[i+1];
  }
  pos[st_size-1] = INF;
  for(int i = st_size-2; i >= 0; i--) {
    if(pos[i] > pos[i+1]) pos[i] = pos[i+1];
  }

  // for(int i = 0; i < st_size; i++) {
  //   cout << "pos[" << i << "]: " << pos[i] << endl;
  // }

  int ans = INF;

  for(int i = k-1; i >= 0; i--) {
    if(pos[a[i]] != INF) {
      ans = min(ans, pos[a[i]] - i);
      // cout << "i: " << i << ", " << ans << endl;
    }
  }

  if(ans == INF) cout << "-1\n";
  else cout << ans << endl;
}