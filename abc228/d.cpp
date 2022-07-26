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
saiaku : n^2
---------------------------*/

int main(){
    ll q;
    cin >> q;
    ll n = 1048576;
    vector<ll> a(n, -1);
    vector<ll> nx(n);
    for(ll i = 0; i < n; i++) nx[i] = (i+1)%n;
    for(ll i = 0; i < q; i++) {
        ll t, x;
        cin >> t >> x;
        if(t == 1){
            ll h = x%n;
            while(a[h] != -1) {
                h = nx[h];
            }
            if(x%n != h) nx[x%n] = h;
            a[h] = x;
        }else{
            cout << a[x%n] << endl;
        }
    }
}