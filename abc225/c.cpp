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
2021-11-02 19:52:30
灰色diffの問題くらいはすぐに実装できるべき
しばらく競プロから離れていたので頑張ろう
---------------------------*/

int main(){
    ll h, w;
    cin >> h >> w;
    vector<vector<ll>> a(h, vector<ll>(w));
    for(ll i = 0; i < h; i++) 
        for(ll j = 0; j < w; j++) cin >> a[i][j];
    bool ok = true;
    for(ll i = 0; i < h; i++) {
        if(i == 0) {
            for(ll j = 1; j < w; j++) {
                if(((a[i][j]-1)%7 != (a[i][j-1]-1)%7+1) || (a[i][j] != a[i][j-1]+1)) ok = false;
                // ↑　両方の条件が必要 after_contest
            }
        } else {
            for(ll j = 0; j < w; j++) {
                if(a[i][j] != a[i-1][j]+7) ok = false;
            }
        }
    }
    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;
}

/*
 1  2  3  4  5  6  7 
 8  9 10 11 12 13 14
15 16 ...

(a[i][j]-1)%7 : retu 0~6
(a[i][j]-1)/7 : gyou 0~
*/

