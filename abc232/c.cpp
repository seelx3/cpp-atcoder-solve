#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)(v.size())

int main() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> ab(m), cd(m);
  for (int i = 0; i < m; i++) {
    cin >> ab[i].first >> ab[i].second;
    ab[i].first--;
    ab[i].second--;
  }
  for (int i = 0; i < m; i++) {
    cin >> cd[i].first >> cd[i].second;
    cd[i].first--;
    cd[i].second--;
  }

  sort(ALL(ab));
  sort(ALL(cd));
  vector<int> id(n);
  for (int i = 0; i < n; i++) {
    id[i] = i;
  }
#ifdef DEBUG
  for (int i = 0; i < m; i++) {
    cout << ab[i].first << " " << ab[i].second << ", ";
  }
  cout << endl;
  cout << "----" << endl;
#endif

  vector<pair<int, int>> vp(m);
  bool same = false;
  do {
    for (int i = 0; i < m; i++) {
      vp[i] = {id[cd[i].first], id[cd[i].second]};
      if (vp[i].first > vp[i].second)
        swap(vp[i].first, vp[i].second);
    }
    sort(ALL(vp));
#ifdef DEBUG
    for (int i = 0; i < m; i++) {
      cout << vp[i].first << " " << vp[i].second << ", ";
    }
    cout << endl;
#endif
    if (vp == ab)
      same = true;
  } while (next_permutation(ALL(id)));

  if (same)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}