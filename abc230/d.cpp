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
    ll n, d;
    cin >> n >> d;
    vector<pair<ll, ll>> vp(n);
    for(ll i = 0; i < n; i++) cin >> vp[i].second >> vp[i].first;

    sort(ALL(vp)); // 右端でソート

    ll ans = 0, hakai = -1;
    for(ll i = 0; i < n; i++) {
        if(i == 0) {
            hakai = vp[i].first + d - 1;
            ans = 1;
        } else {
            if(vp[i].second <= hakai) continue;
            else{
                hakai = vp[i].first + d - 1;
                ans++;
            }
        }
    }
    
    cout << ans << endl;
}