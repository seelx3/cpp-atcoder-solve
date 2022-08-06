#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)v.size()

int main() {
  ll n;
  cin >> n;
  vector<int> c(10);
  int min_c = INT_MAX;
  for (int i = 1; i <= 9; i++) {
    cin >> c[i];
    min_c = min(min_c, c[i]);
  }

  int length = n / min_c;

  // 長さlengthでもっとも大きくなるようにしたい
  // 先頭から貪欲
  // 残りの予算が(残りの長さ)*min_c以上ならok

  string ans = "";
  for (int i = 0; i < length; i++) {
    for (int j = 9; j >= 1; j--) {
      if (min_c * (length - i - 1) + c[j] <= n) {
        ans.push_back((char)('0' + j));
        n -= c[j];
        break;
      }
    }
  }

  cout << ans << endl;
}