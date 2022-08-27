#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)(v.size())

using P = pair<ll, ll>;
const ll inf = LONG_LONG_MAX;

int main() {
  ll N, D;
  cin >> N >> D;
  vector<P> seq(N); // (r, l)
  for (int i = 0; i < N; i++) {
    cin >> seq[i].second >> seq[i].first;
  }
  sort(ALL(seq));
  ll id = 0;
  ll r = 0;
  ll ans = 0;
  while (true) {
    ans++;
    r = seq[id].first + D - 1;
    while (seq[id].second <= r || seq[id].first <= r) {
      id++;
      if (id > N) {
        cout << ans << endl;
        return 0;
      }
    }
  }
}