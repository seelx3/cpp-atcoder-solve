#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(),v.end()
#define sz(v) (int)v.size()

int main(){
  int Q;
  cin >> Q;
  deque<pair<ll, ll>> dq;
  while(Q--) {
    int sw;
    cin >> sw;
    if(sw == 1) {
      ll x, c;
      cin >> x >> c;
      dq.push_back({x, c});
    } else {
      ll c;
      cin >> c;
      ll ans = 0;
      while(c > 0) {
        auto left = dq.front();
        dq.pop_front();
        if(left.second > c) {
          ans += left.first*c;
          dq.push_front({left.first, left.second-c});
          c = 0;
        } else if(left.second <= c) {
          ans += left.first*left.second;
          c -= left.second;
        }
      }
      cout << ans << endl;
    }
  }
}