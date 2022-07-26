#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)
#define ALL(v) v.begin(),v.end()
#define sz(v) (ll)v.size()
const ll INF = __LONG_LONG_MAX__;
// const ll MOD = 998244353;
const ll MOD = 1000000007;
ll dx[] = {1, 0, -1, 0};
ll dy[] = {0, 1, 0, -1};
const double PI = acos(-1.0);

/*---------------------------
---------------------------*/

void tripleShift(vector<int>& s, int i){
  int z = s[i+2];
  s[i+2] = s[i+1];
  s[i+1] = s[i];
  s[i] = z;
  return;
}

int main(){
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for(int i = 0; i < n; i++) { cin >> a[i]; }
  for(int i = 0; i < n; i++) { cin >> b[i]; }

  vector<int> a_sorted = a, b_sorted = b;
  sort(ALL(a_sorted));
  sort(ALL(b_sorted));
  if(a_sorted != b_sorted) {
    cout << "No" << endl;
    return 0;
  }

  bool f = false;
  for(int i = 0; i < sz(a_sorted)-1; i++) {
    if(a_sorted[i] == a_sorted[i+1]) f = true;
  }

  for(int i = 0; i < n-2; i++) {
    if(a[i] == b[i]) continue;
    // b[i]と等しい要素をi+1かi+2までもってくる
    int idx = -1;
    for(int j = i+1; j < n; j++) {
      if(a[j] == b[i]) {
        idx = j;
      }
    }
    while(idx > i+2) {
      tripleShift(a, idx-2);
      idx -= 2;
    }
    //
    if(a[i+2] == b[i]) tripleShift(a, i);
    else if(a[i+1] == b[i]) {
      tripleShift(a, i);
      tripleShift(a, i);
    }
    
    // debug
    // for(int i = 0; i < n; i++) { cout << a[i] << " \n"[i==n-1]; }
  }

  bool ans = false;
  if(a == b) ans = true;
  tripleShift(a, n-3);
  if(a == b) ans = true;
  tripleShift(a, n-3);
  if(a == b) ans = true;
  if(f) ans = true;

  cout << (ans ? "Yes" : "No") << endl;

}