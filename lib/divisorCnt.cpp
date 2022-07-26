/**
 * @file divisorCnt.cpp
 * @brief Prime factorization (素因数分解)
 * @date 2022/02/22
 *
 */

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)
#define ALL(v) v.begin(),v.end()
#define sz(v) (ll)v.size()
const ll INF = 1e18;
const ll MOD = 998244353; 
// const ll MOD = 1000000007;
ll dx[] = {1, 0, -1, 0};
ll dy[] = {0, 1, 0, -1};
const double PI = acos(-1.0);

//--------------------------------------------------
// 素因数分解し、各素因数の個数を求める
//--------------------------------------------------

vector<long long> make_min_factor(ll n){
    vector<long long> ret(n, 100100100100100100);
    ret[0] = -1, ret[1] = -1;
    for(long long i = 2; i < n; i++) {
        for(int j = i; j < n; j+=i) {
            ret[j] = min(ret[j], i);
        }
    }
    return ret;
}

int main() {
    ll n; cin >> n;
    vector<ll> min_factor = make_min_factor(n+1);
    map<ll, ll> mp;
    ll _n = n;
    while(min_factor[_n]!=-1){
        mp[min_factor[_n]]++;
        _n /= min_factor[_n];
    }
    for(auto it : mp){
        cout << it.first << " : " << it.second << endl;
    }

    return 0;
} 
