#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(),v.end()
#define sz(v) (int)v.size()

int main(){
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n), tmpa;
  for(int i = 0; i < n; i++) { cin >> a[i]; }
  tmpa = a;
  sort(ALL(tmpa));
  for(int i = 0; i < k; i++) {
    multiset<ll> s1, s2;
    for(int j = i; j < n; j+=k) {
      s1.insert(a[j]);
      s2.insert(tmpa[j]);
    }
    if(s1 != s2) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}