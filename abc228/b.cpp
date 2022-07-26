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
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    for(ll i = 0; i < n; i++) cin >> a[i];

    x--;
    vector<bool> seen(n, false);
    while(true){
        seen[x] = true;
        ll nx = a[x]-1;
        if(seen[nx]) break;
        x = nx;
    }

    ll ans = 0;
    for(ll i = 0; i < n; i++) {
        if(seen[i]) ans++;
    }

    cout << ans << endl;
}