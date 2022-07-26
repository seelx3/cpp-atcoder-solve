#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(),v.end()
#define sz(v) (int)v.size()

void ret(int x) {
  if(x == 1) {
    cout << "1";
    return;
  }
  ret(x-1);
  cout << " " << x << " ";
  ret(x-1);
  return;
}

int main(){
  int n;
  cin >> n;

  ret(n);
  cout << "\n";
}