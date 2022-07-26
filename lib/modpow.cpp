#include <bits/stdc++.h>
using namespace std;

//繰り返し2乗法　計算量O(log N)

long long modpow(long long x, long long n, long long m) {
    long long ret = 1;
    while (n > 0) {
        if (n & 1) ret = ret * x % m;
        x = x * x % m;
        n >>= 1; 
    }
    return ret;
}


