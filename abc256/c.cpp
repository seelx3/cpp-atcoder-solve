#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(),v.end()
#define sz(v) (int)v.size()

int main(){
  ll h1, h2, h3, w1, w2, w3;
  cin >> h1 >> h2 >> h3 >> w1 >> w2 >> w3;

  ll ans = 0;
  for(int a = 1; a <= 30; a++) {
    for(int b = 1; b <= 30; b++) {
      for(int c = 1; c <= 30 ; c++) {
        for(int d = 1; d <= 30; d++) {
          int p13 = h1 - a - b;
          int p23 = h2 - c - d;
          int p31 = w1 - a - c;
          int p32 = w2 - b - d;
          int p33h = w3 - p13 - p23;
          int p33w = h3 - p31 - p32;
          if(p13 > 0 && p23 > 0 && p31 > 0 && p32 > 0 && p33h > 0 && p33h == p33w) ans++;
        }
      }
    }
  }

  cout << ans << endl;
}