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

int main() {
  int N;
  double A;
  cin >> N >> A;
  vector<int> W(N);
  vector<double> X(N), V(N);

  REP(i, N) cin >> W[i] >> X[i] >> V[i];

  int ans = 0;

  REP(i, N) {
    // i 番目の魚を左端としたときの区間
    deb(i);
    map<double, int> mp;
    mp[1e10] = 0;
    mp[1e11] = 0;
    REP(j, N) {
      if (j == i) continue;

#ifdef LOCAL
      if (V[i] - V[j] == 0 && X[j] - X[i] <= A) {
        double t1 = 0;
        double t2 = 1e11;
        deb(j, W[j], t1, t2);
        continue;
      }
#endif

      if (V[i] - V[j] == 0) continue;
      double t1 = (X[j] - X[i]) / (V[i] - V[j]);
      double t2 = (X[j] - X[i] - A) / (V[i] - V[j]);
      if (t2 < t1) swap(t1, t2);
      if (t2 < 0.0) continue;
      if (t1 < 0.0) t1 = 0.0;
      mp[t1] = 0;
      mp[t2] = 0;
      deb(j, W[j], t1, t2);
    }
    deb(mp);
    REP(j, N) {
      if (j == i) continue;
      if (V[i] - V[j] == 0) {
        if (X[j] >= X[i] && X[j] - X[i] <= A) {
          mp[0] += W[j];
          mp[1e11] -= W[j];
        }
        continue;
      }
      double t1 = (X[j] - X[i]) / (V[i] - V[j]);
      double t2 = (X[j] - X[i] - A) / (V[i] - V[j]);
      if (t2 < t1) swap(t1, t2);
      if (t2 < 0.0) continue;
      if (t1 < 0.0) t1 = 0.0;
      mp[t1] += W[j];
      auto it = next(mp.find(t2));
      it->second -= W[j];
    }
    deb(mp);
    for (auto it = next(mp.begin()); it != mp.end(); it++) {
      it->second += prev(it)->second;
    }
    deb(mp);
    for (auto& it : mp) {
      chmax(ans, it.second + W[i]);
    }
    deb(ans);
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