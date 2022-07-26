#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)v.size()

struct section {
  int l;
  int r;
};

int main() {
  int n;
  cin >> n;
  vector<section> sc(n);
  for (int i = 0; i < n; i++) {
    cin >> sc[i].l >> sc[i].r;
  }
  sort(ALL(sc), [](section& s1, section& s2) { return s1.l < s2.l; });

  for (int i = 0; i < n; i++) {
    int le = sc[i].l;
    int ri = sc[i].r;
    while (i + 1 < n && ri >= sc[i + 1].l) {
      ri = max(ri, sc[i + 1].r);
      i++;
    }
    cout << le << " " << ri << endl;
  }
}