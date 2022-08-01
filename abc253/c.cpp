#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)v.size()

int main() {
  multiset<ll> ms;

  ll q;
  cin >> q;

  for (int i = 0; i < q; i++) {
    int id;
    cin >> id;
    if (id == 1) {
      ll x;
      cin >> x;
      ms.insert(x);
    } else if (id == 2) {
      ll x, c;
      cin >> x >> c;
      while (c-- && ms.find(x) != ms.end()) {
        ms.erase(ms.find(x));
      }
    } else if (id == 3) {
      cout << *ms.rbegin() - *ms.begin() << endl;
    }
  }
}