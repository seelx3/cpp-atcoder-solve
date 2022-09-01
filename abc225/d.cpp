#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)(v.size())

int main() {
  ll n, q;
  cin >> n >> q;

  vector<ll> frnt(n + 1, -1), bck(n + 1, -1);

  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int x, y;
      cin >> x >> y;
      bck[x] = y;
      frnt[y] = x;
    } else if (t == 2) {
      int x, y;
      cin >> x >> y;
      bck[x] = -1;
      frnt[y] = -1;
    } else if (t == 3) {
      int x;
      cin >> x;
      int tp = x;
      while (frnt[tp] != -1) {
        tp = frnt[tp];
      }
      vector<ll> ans;
      while (bck[tp] != -1) {
        ans.push_back(tp);
        tp = bck[tp];
      }
      ans.push_back(tp);

      cout << sz(ans) << " ";
      for (int i = 0; i < sz(ans); i++) {
        cout << ans[i] << " \n"[i == sz(ans) - 1];
      }
    }
  }
}