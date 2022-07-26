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
//--------------------------------------------------

vector<long long> tsort(vector<vector<long long>> G){
    vector<long long> in(sz(G)); // 入次数
    for(long long i = 0; i < sz(G); i++) {
        for(long long j = 0; j < sz(G[i]); j++) in[G[i][j]]++;
    }
    queue<long long> qu;
    for(long long i = 0; i < sz(G); i++) {
        if(in[i]==0) qu.push(i);
    }
    vector<long long> ret;
    while(!qu.empty()){
        long long u = qu.front(); qu.pop();
        ret.push_back(u);
        for(long long i = 0; i < sz(G[u]); i++) {
            long long v = G[u][i];
            in[v]--;
            if(in[v]==0) qu.push(v);
        }
    }
    return ret;
}

int main() {
    long long V, E;
    cin >> V >> E;
    vector<vector<long long>> G(V);
    for(int i = 0; i < E; i++) {
        int s, t;
        cin >> s >> t;
        G[s].push_back(t);
    }
    vector<ll> ans = tsort(G);
    for(ll i = 0; i < sz(ans); i++) cout << ans[i] << " \n"[i==sz(ans)-1];

    return 0;
} 

/*
10 9
0 1
1 3
3 2 
3 4
4 5
5 6
6 7
7 8
8 9
*/