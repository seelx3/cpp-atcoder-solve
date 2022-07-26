#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)v.size()

int main() {
  int n, k, q;
  cin >> n >> k >> q;
  vector<int> a(k);
  for (int i = 0; i < k; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < q; i++) {
    int l;
    cin >> l;
    if (l == k) {
      if (a[l - 1] + 1 <= n)
        a[l - 1]++;
      continue;
    }
    if (a[l - 1] + 1 < a[l])
      a[l - 1]++;
  }
  for (int i = 0; i < k; i++) {
    cout << a[i] << " \n"[i == k - 1];
  }
}