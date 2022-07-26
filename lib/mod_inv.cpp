#include <bits/stdc++.h>
using namespace std;
#define ll long long

long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

ll gcd(ll a,ll b){
    if(a<b)swap(a,b);
    if(a%b==0)return b;
    return gcd(a%b,b);
}

int main() {
    ll m;
    cin >> m;
    for(ll a = 1; a < m; a++){
        cout << a << ": ";
        if(gcd(a, m) == 1) cout << modinv(a, m) << endl;
        else cout << -1 << endl;
    } 
    
    return 0;
} 