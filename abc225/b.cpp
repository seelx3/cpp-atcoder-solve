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
    vector<ll> cnt(n+1, 0);
    for(ll i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        cnt[a]++;
        cnt[b]++;
    }
    bool ok = false;
    for(ll i = 1; i < n+1; i++) {
        if(cnt[i] == n) ok = true;
    }
    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;
}