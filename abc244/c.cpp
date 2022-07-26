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

int main(){
  int n;
  cin >> n;
  set<int> st;
  for(int i = 1; i <= n*2+1; i++) st.insert(i);

  while(!st.empty()) {
    int tk = *st.begin();
    cout << tk << endl;
    st.erase(tk);

    if(st.empty()) break;

    int ao;
    cin >> ao;
    st.erase(ao);
  }

  int fin;
  cin >> fin;

  return 0;
}