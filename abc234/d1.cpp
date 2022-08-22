#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)(v.size())

int main() {
  ll n, k;
  cin >> n >> k;
  priority_queue<ll, vector<ll>, greater<ll>> pq;
  for (int i = 0; i < n; i++) {
    ll p;
    cin >> p;
    if (i < k - 1) {
      pq.push(p);
    } else if (i >= k) {
      ll minp = pq.top();
      if (p > minp) {
        pq.pop();
        pq.push(p);
      }
      cout << pq.top() << endl;
    } else if (i == k - 1) {
      pq.push(p);
      cout << pq.top() << endl;
    }
  }
}