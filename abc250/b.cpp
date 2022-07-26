#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(),v.end()
#define sz(v) (int)v.size()

int main(){
  int n, a, b;
  cin >> n >> a >> b;

  for(int i = 0; i < n*a; i++) {
    for(int j = 0; j < n*b; j++) {
      if(((i/a)%2 + (j/b)%2)%2) cout << "#";
      else cout << ".";
    }
    cout << endl;
  }
}