#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct BIT {
    int n;          // 配列の要素数(数列の要素数+1)
    vector<T> bit;  // データの格納先
    BIT(int n_) : n(n_ + 1), bit(n, 0) {}
    void add(int i, T x) {
        i++;
        for (int idx = i; idx < n; idx += (idx & -idx)) {
            bit[idx] += x;
        }
    }
    T sum(int i) {
        i++;
        T s(0);
        for (int idx = i; idx > 0; idx -= (idx & -idx)) {
            s += bit[idx];
        }
        return s;
    }
    T sub_sum(int l, int r){
        if(l == 0) return sum(r);
        else return sum(r) - sum(l-1);
    }
};

int main(){
    long long n = 10;
    vector<long long> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    BIT<long long> B(n+1);
    // iにv[i]を加える
    for(int i = 0; i < n; i++) B.add(i, v[i]); 
    // 0~iまでの和
    for(int i = 0; i < n; i++) cout << i << " : " << B.sum(i) << endl; 
    // l~rの和を求める
    cout << B.sub_sum(1,2) << endl; 
}