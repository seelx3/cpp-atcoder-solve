#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)v.size()

int main() {
  ll n, x, y, z;
  cin >> n >> x >> y >> z;
  vector<ll> a(n), b(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n; i++)
    cin >> b[i];

  vector<bool> pass(n);

  auto comp = [](pair<ll, ll>& p1, pair<ll, ll>& p2) {
    if (p1.first == p2.first)
      return p1.second < p2.second;
    return p1.first > p2.first;
  };

  vector<pair<ll, ll>> vp1, vp2, vp3;
  for (int i = 0; i < n; i++) {
    vp1.push_back({a[i], i});
  }
  sort(ALL(vp1), comp);
  for (int i = 0; i < x; i++) {
    pass[vp1[i].second] = true;
  }

  for (int i = 0; i < n; i++) {
    if (!pass[i])
      vp2.push_back({b[i], i});
  }
  sort(ALL(vp2), comp);
  for (int i = 0; i < y; i++) {
    pass[vp2[i].second] = true;
  }

  for (int i = 0; i < n; i++) {
    if (!pass[i])
      vp3.push_back({a[i] + b[i], i});
  }
  sort(ALL(vp3), comp);
  for (int i = 0; i < z; i++) {
    pass[vp3[i].second] = true;
  }

  for (int i = 0; i < n; i++) {
    if (pass[i])
      cout << i + 1 << endl;
  }
}