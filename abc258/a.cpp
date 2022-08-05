#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)v.size()

int main() {
  int k;
  cin >> k;
  if (k < 60) {
    printf("21:%02d\n", k);
  } else {
    printf("22:%02d\n", k % 60);
  }
}