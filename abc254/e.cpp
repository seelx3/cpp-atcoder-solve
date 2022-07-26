#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(),v.end()
#define sz(v) (int)v.size()

int main(){
  ll n, m;
  cin >> n >> m;
  vector<vector<ll>> G(n);
  for(int i = 0; i < m; i++) {
    ll a, b;
    cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  ll q;
  cin >> q;
  for(int i = 0; i < q; i++) {
    ll x, k;
    cin >> x >> k;
    x--;
    set<ll> st;
    st.insert(x);
    if(k >= 1) {
      for(auto v1 : G[x]) {
        st.insert(v1);
        if(k >= 2) {
          for(auto v2 : G[v1]) {
            st.insert(v2);
            if(k >= 3) {
              for(auto v3 : G[v2]) {
                st.insert(v3);
              }
            }
          }
        }
      }
    }
    ll ans = 0;
    for(auto it : st) {
      ans += it+1;
    } 
    cout << ans << endl;
  }
}