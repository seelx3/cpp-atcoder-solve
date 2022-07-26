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

int main(){
    ll n;
    vector<bool> ok(2000, false);
    for(ll a = 1; a <= 1000; a++){
        for(ll b = 1; b <= 1000; b++) {
            ll c = 4*a*b + 3*a + 3*b;
            if(c > 1000) continue;
            ok[c] = true;
        } 
    } 
    cin >> n;
    ll ans = 0;
    for(ll i = 0; i < n; i++) {
        ll s;
        cin >> s;
        if(!ok[s]) ans++;
    }
    cout << ans << endl;
}