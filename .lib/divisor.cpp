#include <bits/stdc++.h>
using namespace std;

//約数列挙
vector<long long> divisor(long long n) {
    vector<long long> ret;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i * i != n) ret.push_back(n / i);
        }
    }
    sort(ret.begin(), ret.end());
    return ret;
}

int main(){
    long long n;
    cin >> n;
    vector<long long> d = divisor(n);
    for(int i = 0; i < (int)d.size(); i++) cout << d[i] << endl;
}