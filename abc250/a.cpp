#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(),v.end()
#define sz(v) (int)v.size()

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main(){
  int h, w, r, c;
  cin >> h >> w >> r >> c;

  int ans = 0;

  for(int i = 0; i < 4; i++) {
    int x = r + dx[i];
    int y = c + dy[i];
    if(x >= 1 && x <= h && y >= 1 && y <= w) ans++;
  }

  cout << ans << endl;
  return 0;
}