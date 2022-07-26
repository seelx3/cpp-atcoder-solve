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
    string a, b;
    a = s, b = s;
    for(ll i = 0; i < sz(s); i++) {
        s = s[sz(s)-1] + s.substr(0, sz(s)-1);
        chmin(a, s);
        chmax(b, s);
    }
    cout << a << "\n" << b << endl;
}