#include <bits/stdc++.h>
using namespace std;

// base 10 -> base n
vector<long long> to_base_n(long long x, long long n){
    vector<long long> ret;
    while(x){
        ret.push_back(x%n);
        x /= n;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

//ex
int main(){
    vector<long long> v = to_base_n(1023, 2);
    for(int i = 0; i < (int)v.size(); i++) cout << v[i]; // 111111111
    cout << endl;
}