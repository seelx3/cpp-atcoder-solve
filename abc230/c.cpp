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
    ll n, a, b, p, q, r, s;
    cin >> n >> a >> b;
    cin >> p >> q >> r >> s;

    string t = "";
    for(ll i = 0; i <= s-r; i++) t.push_back('.');
    vector<string> ans(q-p+1, t);

    for(ll i = 0; i <= q-p; i++) {
        for(ll j = 0; j <= s-r; j++) {
            // (i+p, j+r) が黒いかどうか
            if(i+p-a == j+r-b){
                ll k = i+p-a;
                if(k >= (1-a, 1-b) && k <= (n-a, n-b)) ans[i][j] = '#';
            }
            if(i+p-a == b-j-r){
                ll k = i+p-a;
                if(k >= (1-a, b-n) && k <= (n-a, b-1)) ans[i][j] = '#';
            }
        }
    }

    for(ll i = 0; i <= q-p; i++) cout << ans[i] << endl;
}