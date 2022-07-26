#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(),v.end()
#define sz(v) (int)v.size()

int x;

int ret(int a, int b, int c){
  return b * (a*(x/(a+c)) + min(x%(a+c), a));
}

int main(){
  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f >> x;
  int takahashi = ret(a, b, c);
  int aoki = ret(d, e, f);
  // cout << takahashi << " " << aoki << endl;
  if(takahashi > aoki) {
    cout << "Takahashi" << endl;
  } else if(takahashi == aoki) {
    cout << "Draw" << endl;
  } else {
    cout << "Aoki" << endl;
  }
  return 0;
}