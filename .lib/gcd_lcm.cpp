#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll gcd(ll a,ll b){
    if(a%b==0)return b;
    return gcd(b, a%b);
}
ll lcm(ll a,ll b){
    return a/gcd(a,b)*b;
}