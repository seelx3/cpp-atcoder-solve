/**
 * @file pf.cpp
 * @brief Prime factorization (素因数分解)
 * @date 2022/11/27
 */

#include <bits/stdc++.h>
using namespace std;

// O(sqrt(N))
vector<pair<long long, long long>> prime_factorize(long long N) {
  vector<pair<long long, long long>> res;
  for (long long a = 2; a * a <= N; ++a) {
    if (N % a != 0) continue;
    long long ex = 0;
    while (N % a == 0) {
      ++ex;
      N /= a;
    }
    res.push_back({a, ex});
  }

  if (N != 1) res.push_back({N, 1});
  return res;
}