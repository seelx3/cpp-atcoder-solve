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
    vector<double> a(n), b(n);
    double c = 0;
    for(ll i = 0; i < n; i++) cin >> a[i] >> b[i], c += a[i]/b[i];
    c /= 2;
    double ans = 0;
    for(ll i = 0; i < n; i++) {
        if(c*b[i] >= a[i]){
            ans += a[i];
            c -= a[i]/b[i];
        }else if(c > 0){
            ans += c*b[i];
            break;
        }
    }
    cout << setprecision(10) << fixed << ans << endl;
}