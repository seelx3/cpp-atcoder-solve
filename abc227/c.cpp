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
    cin >> n;
    ll ans = 0;
    for(ll a = 1; a <= n; a++) {
        if(a*a*a > n) break;
        for(ll b = a; b <= n; b++) {
            if(a*b*b > n) break;
            ll c = n/(a*b);
            // cout << a << " " << b << " " << c << endl;
            ans += c-(b-1);
        }
    }
    cout << ans << endl;
}