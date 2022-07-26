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
    ll h, w;
    cin >> h >> w;
    vector<vector<ll>> a(h, vector<ll>(w));
    for(ll i = 0; i < h; i++) 
        for(ll j = 0; j < w; j++) cin >> a[i][j];
    bool ok = true;
    for(ll i = 0; i < h; i++) {
        for(ll j = 0; j < w; j++) {
            for(ll k = 0; k < h; k++) {
                for(ll l = 0; l < w; l++) {
                    if(i < k && j < l && a[i][j]+a[k][l] > a[k][j]+a[i][l]) ok = false;
                }   
            }   
        }
    }
    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;
}