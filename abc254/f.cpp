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

ll op(ll a, ll b) { return gcd(a, b); }

ll e() { return 0LL; }

int main() {
  ll N, Q;
  cin >> N >> Q;
  vector<ll> A = input(N);
  vector<ll> B = input(N);

  vector<ll> dA(N - 1), dB(N - 1);
  REP(i, N - 1) dA[i] = abs(A[i] - A[i + 1]);
  REP(i, N - 1) dB[i] = abs(B[i] - B[i + 1]);

  segtree<ll, op, e> segA(N - 1), segB(N - 1);
  REP(i, N - 1) {
    segA.set(i, dA[i]);
    segB.set(i, dB[i]);
  }

  // deb(segA.prod(0, 1));
  // deb(segA.prod(0, 2));
  // deb(segA.prod(1, 2));

  while (Q--) {
    ll h1, h2, w1, w2;
    cin >> h1 >> h2 >> w1 >> w2;
    h1--, h2--;
    w1--, w2--;
    ll ans = gcd(segA.prod(h1, h2), segB.prod(w1, w2));
    ans = gcd(ans, A[h1] + B[w1]);
    cout << ans << endl;
  }
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