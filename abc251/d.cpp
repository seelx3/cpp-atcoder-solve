#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)v.size()

int main() {
  ll w;
  cin >> w;

  vector<ll> ans;
  ll a[] = {1, 100, 10000};

  for (int i = 0; i < 3; i++) {
    for (int j = 1; j < 100; j++) {
      ans.push_back(a[i] * j);
    }
  }
  ans.push_back(1000000);

  cout << sz(ans) << endl;
  for (int i = 0; i < sz(ans); i++) {
    cout << ans[i] << " \n"[i == sz(ans) - 1];
  }
}