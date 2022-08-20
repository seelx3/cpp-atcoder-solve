#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)(v.size())

using P = pair<ll, ll>;

int main() {
  ll n, K, m;
  cin >> n >> m >> K;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  vector<vector<P>> v(40); // cost, value
  ll ans = 0;

  for (int i = 0; i < n; i++) {
    v[31].push_back({0, a[i]});
  }
  int used = 31;
  for (int i = 30; i >= 0; i--) {
    for (int j = 0; j < n; j++) {
      if ((v[used][j].second >> i) & 1) {
        v[i].push_back({v[used][j].first, v[used][j].second % (1 << i)});
      } else {
        ll mins = v[used][j].second % (1 << i);
        v[i].push_back({v[used][j].first + (1 << i) - mins, 0});
      }
    }
#ifdef DEBUG
    cout << i << "-------" << endl;
    for (int j = 0; j < n; j++) {
      cout << "{" << v[i][j].first << ", " << v[i][j].second << "}"
           << ",\n"[j == n - 1];
    }
#endif
    sort(ALL(v[i]));
    ll su = 0;
    bool ok = true;
    for (int j = 0; j < K; j++) { // K要素選択
      su += v[i][j].first;
      if (su > m) { // 操作はm以下
        ok = false;
        break;
      }
    }
    if (ok) {
      used = i;
      ans += (1 << i);
    }
#ifdef DEBUG
    cout << "used: " << used << endl;
#endif
  }

  cout << ans << endl;
}