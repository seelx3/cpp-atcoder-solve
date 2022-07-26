#include <stdio.h>
#include <iostream>
#include <vector>
#include <complex>
using namespace std;
const double PI = acos(-1);
#define sz(vec) (int)vec.size()

int main(int argc, char const *argv[]){
    time_t clock_start, clock_end;
    clock_start = clock();
    int sz_f0, sz_f1;
    // cin >> sz_f0 >> sz_f1;
    sz_f0 = atoi(argv[1]), sz_f1 = atoi(argv[1]);
    vector<int> f0(sz_f0), f1(sz_f1);
    for(int i = 0; i < sz_f0; i++) 
        f0[i] = rand();
    for(int i = 0; i < sz_f1; i++) 
        f1[i] = rand();
    vector<int> multiply_ab(sz_f0+sz_f1-1, 0);

    for(int i = 0; i < sz_f0; i++) {
        for(int j = 0; j < sz_f1; j++) {
            multiply_ab[i+j] += f0[i]*f1[j];
        }
    }

    for(int i = 0; i <= sz(multiply_ab); i++){
        // cout << multiply_ab[i] << " \n"[i==sz(multiply_ab)];
    }
    clock_end = clock();
    cout << "time: " << (double)(clock_end-clock_start)/(double)(CLOCKS_PER_SEC) << endl;
}