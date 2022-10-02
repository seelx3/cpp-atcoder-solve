#ifndef INCLUDED_MAIN
#define INCLUDED_MAIN

#include <bits/stdc++.h>
using namespace std;

#include <atcoder/all>
using namespace atcoder;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define SZ(v) (int)(v.size())

#include __FILE__

vector<bool> make_is_prime(int N) {
  vector<bool> prime(N + 1, true);
  if (N >= 0) prime[0] = false;
  if (N >= 1) prime[1] = false;
  for (int i = 2; i * i <= N; i++) {
    if (!prime[i]) continue;
    for (int j = i * i; j <= N; j += i) {
      prime[j] = false;
    }
  }
  return prime;
}

int main() {
  auto prime = make_is_prime(2000005);

  int N = input();

  if (N == 3) {
    cout << "2 4 5\n";
    cout << "7 8 1\n";
    cout << "3 6 9\n";
    return 0;
  }

  if (N == 4) {
    cout << "15 11 16 12\n";
    cout << "13 3 6 9\n";
    cout << "14 7 8 1\n";
    cout << "4 2 10 5\n";
    return 0;
  }

  if (N == 5) {
    cout << "11 13 15 17 19\n";
    cout << "21 23 25 9 7\n";
    cout << "1 5 3 12 2\n";
    cout << "8 4 6 10 14\n";
    cout << "16 18 20 22 24\n";
    return 0;
  }

  vector<bool> used(N * N + 5);

  vector<int> u(N), d(N);
  REP(i, N) {
    u[i] = 3 * (i * 2 + 1);
    d[i] = 3 * (i * 2 + 2);
    used[u[i]] = true;
    used[d[i]] = true;
  }

  auto ans = make_vec(N, N, -1);

  REP(i, N) {
    if (N % 2 != 0) {
      if (i > N / 2) {
        ans[N / 2 - 1][i] = u[i];
        ans[N / 2][i] = d[i];
      } else {
        ans[N / 2][i] = u[i];
        ans[N / 2 + 1][i] = d[i];
      }
    } else {
      ans[N / 2 - 1][i] = u[i];
      ans[N / 2][i] = d[i];
    }
  }

  int now = 1;
  REP(i, N) REP(j, N) {
    while (now <= N * N && used[now])
      now += 2;
    if (now > N * N) break;
    ans[i][j] = now;
    used[now] = true;
  }

  now = 2;
  REPR(i, N) REPR(j, N) {
    while (now <= N * N && used[now])
      now += 2;
    if (now > N * N) break;
    ans[i][j] = now;
    used[now] = true;
  }

  REP(i, N) REP(j, N) cout << ans[i][j] << " \n"[j == N - 1];
}

/*-----------------------------------------------------------
-----------------------------------------------------------*/

#else // INCLUDED_MAIN

#define cauto const auto&

#define OVERLOAD_REP(_1, _2, _3, _4, name, ...) name
#define REP1(i, n) REP3(i, 0, n, 1)
#define REP2(i, a, b) REP3(i, a, b, 1)
#define REP3(i, a, b, c) for (int i = int(a); i < int(b); i += c)
#define REP(...) OVERLOAD_REP(__VA_ARGS__, REP3, REP2, REP1, )(__VA_ARGS__)

#define OVERLOAD_REPR(_1, _2, _3, _4, name, ...) name
#define REPR1(i, n) REPR3(i, 0, n, 1)
#define REPR2(i, a, b) REPR3(i, a, b, 1)
#define REPR3(i, a, b, c) for (int i = int(b) - 1; i >= int(a); i -= c)
#define REPR(...) OVERLOAD_REPR(__VA_ARGS__, REPR3, REPR2, REPR1, )(__VA_ARGS__)

// clang-format off
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

template< typename T, typename U >
static inline vector<U> make_vec(T&& n, U&& val) noexcept {
  return vector<U>(forward<T>(n), forward<U>(val)); 
}
template< typename T, typename... Args >
static inline decltype(auto) make_vec(T&& n, Args&&... args) noexcept {
  return vector<decltype(make_vec(forward<Args>(args)...))>(forward<T>(n), make_vec(forward<Args>(args)...));
}

struct input { 
  int n; input() {} input(int n_) : n(n_){};
  template <class T> operator T() { T ret; cin >> ret; return ret; }
  template <class T> operator vector<T>() { vector<T> ret(n); for (int i = 0; i < n; i++) cin >> ret[i]; return ret; }
};
// clang-format on

#ifdef LOCAL
#include <debug.hpp>
#define deb(...) debug::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define deb(...) (static_cast<void>(0))
#endif

#endif // INCLUDED_MAIN