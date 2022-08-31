#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)
#define ALL(v) v.begin(),v.end()
#define sz(v) (ll)v.size()
const ll INF = 1e18;
const ll MOD = 998244353; 

//--------------
// s[0, n-1]とs[i, n-1]の最長共通接頭辞を求める(O(sz(s)))

vector<long long> z_algorithm(string s){
    vector<long long> Z((int)s.size());
    Z[0] = s.size();
    int i = 1, j = 0;
    while(i < s.size()){
        while(i + j < s.size() && s[j] == s[i + j]) j++;
        Z[i] = j;
        if(j == 0){
            i++;
            continue;
        }
        int k = 1;
        while(k < j && k + Z[k] < j){
            Z[i + k] = Z[k];
            k++;
        }
        i += k;
        j -= k;
    }
    return Z;
}

//--------------

int main() {
    string s;
    cin >> s;
    vector<ll> z = z_algorithm(s);
    for(ll i = 0; i < sz(s); i++) cout << i << ": " << z[i] << endl;

    return 0;
} 