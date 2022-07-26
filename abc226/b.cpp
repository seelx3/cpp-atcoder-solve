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
tokikatagawakaranai
-> set tsukau atteta...
string ni site set tsukattara tle sita
kuhuusureba string demoikeru???
nannde tle ni nattanndaro <- 文字列の結合に時間がかかったたぶん
---------------------------*/


int main(){
    ll n; cin >> n;
    set<vector<ll>> st;
    for(ll i = 0; i < n; i++) {
        ll L; cin >> L;
        vector<ll> v(L);
        for(ll j = 0; j < L; j++) {
            cin >> v[j];
        }
        st.insert(v);
    }
    cout << sz(st) << endl;
}

// int main(){
//     ll n; cin >> n;
//     set<string> st;
//     cin.ignore(); // 改行まで読み込むことで次の行から1行ずつ読み込むことができる
//     for(ll i = 0; i < n; i++) {
//         string s;
//         getline(cin, s);
//         cout << s << endl;
//         st.insert(s);
//     }
//     cout << sz(st) << endl;
// }