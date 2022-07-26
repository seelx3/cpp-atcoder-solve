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
2021-11-07 22:02:26
ramuda kannsuu
---------------------------*/

int main(){
    ll n; cin >> n;
    vector<vector<ll>> a(n);
    vector<ll> t(n);
    for(ll i = 0; i < n; i++) {
        cin >> t[i];
        ll k; cin >> k;
        for(ll j = 0; j < k; j++) {
            ll x; cin >> x; x--;
            a[i].push_back(x);
        }
    }

    vector<bool> b(n, false);
    function<ll(ll)> rec = [&](ll x){
        ll sub = 0;
        for(ll i = 0; i < sz(a[x]); i++) {
            if(!b[a[x][i]]){
                sub += rec(a[x][i]);
            }
        }
        sub += t[x];
        b[x] = true;
        return sub;
    };
    cout << rec(n-1) << endl;
}