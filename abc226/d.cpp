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


/*---------------------------
2021-11-07 23:12:13 
tokerumonndai datta
zikan no wariate wo tyannto siro
---------------------------*/

ll gcd(ll a,ll b){
    if(a%b==0)return b;
    return gcd(b, a%b);
}
ll lcm(ll a,ll b){
    return a/gcd(a,b)*b;
}

int main(){
    ll n; cin >> n;
    vector<ll> x(n), y(n);
    for(ll i = 0; i < n; i++) cin >> x[i] >> y[i];
    set<pair<ll, ll>> ans;
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < n; j++) {
            if(i == j) continue;
            ll dx = x[j] - x[i];
            ll dy = y[j] - y[i];
            ll k = 1;
            if(dx == 0) dy = 1;
            else if(dy == 0) dx = 1;
            else k = gcd(dx, dy);
            ans.insert({dx/k, dy/k});
            ans.insert({-dx/k, -dy/k});
        }
    }
    cout << sz(ans) << endl;
}