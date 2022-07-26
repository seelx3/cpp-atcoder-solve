#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)v.size()

int main() {
  ll n;
  cin >> n;
  unordered_map<string, int> mp;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    cout << s;
    if (mp[s]) {
      cout << "(" << mp[s] << ")";
    }
    mp[s]++;
    cout << endl;
  }
}