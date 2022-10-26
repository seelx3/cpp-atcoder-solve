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

// p/q
struct fraction {
  ll p, q;
  fraction(ll P = 0, ll Q = 1) : p(P), q(Q) {
    if (p < 0 && q < 0) {
      p = -p, q = -q;
    } else if (q < 0) {
      p = -p, q = -q;
    }
    ll tmp = gcd(p, q);
    p = p / tmp;
    q = q / tmp;
  }
  bool operator<(const fraction& other) const {
    return p * other.q < other.p * q;
  }
  bool operator<=(const fraction& other) const {
    return p * other.q <= other.p * q;
  }
};

int main() {
  int N;
  int A;
  cin >> N >> A;
  vector<int> W(N);
  vector<int> X(N), V(N);

  REP(i, N) cin >> W[i] >> X[i] >> V[i];

  int ans = 0;
  const fraction FRAC_MIN = fraction(0, 1);
  const fraction FRAC_MAX = fraction((ll)1e11, 1);

  REP(i, N) {
    // i 番目の魚を左端としたときの区間
    vector<pair<fraction, int>> vp;

    REP(j, N) {
      if (j == i) continue;
      if (V[i] - V[j] == 0) {
        if (X[j] >= X[i] && X[j] - X[i] <= A) {
          vp.emplace_back(FRAC_MIN, -W[j]);
          vp.emplace_back(FRAC_MAX, W[j]);
        }
        continue;
      }
      fraction t1 = fraction(X[j] - X[i], V[i] - V[j]);
      fraction t2 = fraction(X[j] - X[i] - A, V[i] - V[j]);
      if (t2 < t1) swap(t1, t2);
      if (t2 < FRAC_MIN) continue;
      if (t1 < FRAC_MIN) t1 = FRAC_MIN;
      vp.emplace_back(t1, -W[j]);
      vp.emplace_back(t2, W[j]);
    }

    sort(ALL(vp));

#ifdef LOCAL
    for (auto [f, w] : vp) {
      cout << "(" << (double)f.p / (double)f.q << ", " << -w << ") ";
    }
    cout << '\n';
#endif

    int weight = 0;
    for (auto [f, w] : vp) {
      weight += -w;
      chmax(ans, weight + W[i]);
    }
    chmax(ans, W[i]);
  }

  cout << ans << '\n';
}

/*-----------------------------------------------------------
-----------------------------------------------------------*/

#else // INCLUDED_MAIN

// clang-format off
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

#define OVERLOAD_REPE(_1, _2, _3, _4, name, ...) name
#define REPE1(i, n) REPE3(i, 0, n, 1)
#define REPE2(i, a, b) REPE3(i, a, b, 1)
#define REPE3(i, a, b, c) for (int i = int(a); i <= int(b); i += c)
#define REPE(...) OVERLOAD_REPE(__VA_ARGS__, REPE3, REPE2, REPE1, )(__VA_ARGS__)

#define OVERLOAD_REPRE(_1, _2, _3, _4, name, ...) name
#define REPRE1(i, n) REPRE3(i, 0, n, 1)
#define REPRE2(i, a, b) REPRE3(i, a, b, 1)
#define REPRE3(i, a, b, c) for (int i = int(b); i >= int(a); i -= c)
#define REPRE(...) OVERLOAD_REPRE(__VA_ARGS__, REPRE3, REPRE2, REPE1, )(__VA_ARGS__)

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