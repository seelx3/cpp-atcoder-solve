#include <bits/stdc++.h>
using namespace std;
#define ll long long
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


//---------------------------
//---------------------------

int main(){
    string s;
    cin >> s;
    set<char> st;
    for(ll i = 0; i < 3; i++) st.insert(s[i]);
    if(sz(st) == 1) cout << 1 << endl;
    else if(sz(st) == 2) cout << 3 << endl;
    else cout << 6 << endl;
}