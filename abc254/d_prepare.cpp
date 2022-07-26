#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(),v.end()
#define sz(v) (int)v.size()

int main(){
  cout << "{";
  for(int i = 1; i <= 1000; i++) {
    cout << i*i << ",}"[i==1000];
  }
}