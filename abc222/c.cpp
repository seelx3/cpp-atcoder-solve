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
2021-11-08 06:13:51
2021-11-08 07:21:17
めっちゃ実装で詰まった
なにでソートしているのかをしっかり把握して添え字をミスらないことが大事
つまったらデバッグ
---------------------------*/

int main(){
    ll n, m; cin >> n >> m;
    vector<string> a(2*n);
    vector<pair<ll, ll>> score(2*n);
    for(ll i = 0; i < 2*n; i++) score[i] = {i, 0};
    for(ll i = 0; i < 2*n; i++) cin >> a[i];
    for(ll i = 0; i < m; i++) {
        for(ll j = 0; j < 2*n; j+=2) {
            ll l = score[j].first, r = score[j+1].first;
            if(a[l][i] == a[r][i]) continue;
            if(
                (a[l][i] == 'G' && a[r][i] == 'C') ||
                (a[l][i] == 'C' && a[r][i] == 'P') ||
                (a[l][i] == 'P' && a[r][i] == 'G')
            ) score[j].second++;
            else score[j+1].second++;
        }
        sort(ALL(score), [](auto &left, auto &right){
            if(left.second != right.second) return left.second > right.second;
            return left.first < right.first;
        });
    }
    for(ll i = 0; i < 2*n; i++) cout << score[i].first+1 << endl;
}
