#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)(v.size())

int main() {
  set<char> st;
  for (int i = 0; i < 3; i++) {
    char c;
    cin >> c;
    st.insert(c);
  }
  if (sz(st) == 1)
    cout << 1 << endl;
  else if (sz(st) == 2)
    cout << 3 << endl;
  else
    cout << 6 << endl;
}