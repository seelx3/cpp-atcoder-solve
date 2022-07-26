#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)
#define ALL(v) v.begin(),v.end()
#define sz(v) (ll)v.size()
const ll INF = 1e18;
// const ll MOD = 998244353;
const ll MOD = 1000000007;
ll dx[] = {1, 0, -1, 0};
ll dy[] = {0, 1, 0, -1};
const double PI = acos(-1.0);

/*---------------------------

---------------------------*/

set<int> prime = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199};

int main(){
  int a, b, c, d;
  cin >> a >> b >> c >> d;

  bool chokudai = false;
  for(int i = a; i <= b; i++) {
    bool noPrime = true;
    for(int j = c; j <= d; j++) {
      if(prime.count(i+j)) noPrime = false;
    }
    if(noPrime) chokudai = true;
  }

  if(chokudai) cout << "Takahashi" << endl;
  else cout << "Aoki" << endl;
}