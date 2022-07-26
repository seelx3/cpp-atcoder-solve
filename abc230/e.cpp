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
---------------------------*/

ll rui(ll x, ll y){
    ll ret = 1;
    for(ll i = 0; i < y; i++) ret *= x;
    return ret;
}

int main(){
    ll n;
    cin >> n;
    ll ans = 0;
    for(ll k = 1; k <= (ll)sqrt(n); k++) ans += rui(n, k);
    ans *= 2;
    ans -= ((ll)sqrt(n))*((ll)sqrt(n));
    cout << ans << endl;
}