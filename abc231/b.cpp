#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)(v.size())

#define chmax(a, b) a = max(a, b)

int main() {
  ll n;
  cin >> n;
  map<string, int> mp;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    mp[s]++;
  }

  string ans = "";
  int cnt = 0;
  for (auto it : mp) {
    if (it.second > cnt) {
      cnt = it.second;
      ans = it.first;
    }
  }

  cout << ans << endl;
}