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
    ll n;
    cin >> n;
    vector<pair<ll, ll>> p(n);
    for(ll i = 0; i < n; i++) cin >> p[i].first >> p[i].second;
    sort(ALL(p));
    ll ans = 0;
    for(ll i = 0; i < n; i++) {
        for(ll j = i+1; j < n; j++) {
            for(ll k = j+1; k < n; k++) {
                // (y2-y1)/(x2-x1) == (y3-y1)/(x3-x1)
                ll x1 = p[i].first, x2 = p[j].first, x3 = p[k].first;
                ll y1 = p[i].second, y2 = p[j].second, y3 = p[k].second;
                if(!((y2-y1)*(x3-x1)==(y3-y1)*(x2-x1))) ans++;
            }
        }
    }
    cout << ans << endl;
}