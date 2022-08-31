#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) v.begin(),v.end()

//--------------
//--------------

int main() {
    ll n;
    cin >> n;
    vector<ll> x(n);
    for(ll i = 0; i < n; i++) {
        cin >> x[i];
        x[i];
    }
    vector<ll> ids(n);
    iota(ALL(ids), 0);
    sort(ALL(ids), [&](ll i, ll j){return x[i] < x[j];});
    // もとのidを保持

    return 0;
} 
