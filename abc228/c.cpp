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
    ll n, k;
    cin >> n >> k;
    vector<pair<ll, ll>> p(n);
    for(ll i = 0; i < n; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        p[i] = {a+b+c, i};
    }
    sort(ALL(p));
    vector<ll> pf(n);
    vector<bool> hantei(n, false);
    for(ll i = 0; i < n; i++) pf[i] = p[i].first;

    // cout << "---" << endl;
    // for(ll i = 0; i < n; i++) cout << p[i].first << " " << p[i].second << endl;
    // cout << "---" << endl;

    for(ll i = 0; i < n; i++) {
        // cout << pf.end() - upper_bound(ALL(pf), pf[i]+300) << endl;
        if(pf.end() - upper_bound(ALL(pf), pf[i]+300) <= k-1) hantei[p[i].second] = true;
    }
    for(ll i = 0; i < n; i++) {
        if(hantei[i]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}