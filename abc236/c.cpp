#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)v.size()

int main() {
  ll n, m;
  cin >> n >> m;
  set<string> st;
  vector<string> s(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < m; i++) {
    string t;
    cin >> t;
    st.insert(t);
  }
  for (int i = 0; i < n; i++) {
    if (st.count(s[i]))
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
}