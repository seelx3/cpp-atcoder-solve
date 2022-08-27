#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)(v.size())

int main() {
  int ax, ay, bx, by, cx, cy, dx, dy;
  cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy;

  pair<int, int> bd = {dx - bx, dy - by}, ba = {ax - bx, ay - by},
                 bc = {cx - bx, cy - by};
  pair<int, int> ac = {cx - ax, cy - ay}, ad = {dx - ax, dy - ay},
                 ab = {bx - ax, by - ay};
  if ((bd.first * ba.second - bd.second * ba.first > 0 &&
       bd.first * bc.second - bd.second * bc.first < 0) &&
      (ac.first * ad.second - ac.second * ad.first > 0 &&
       ac.first * ab.second - ac.second * ab.first < 0))
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}