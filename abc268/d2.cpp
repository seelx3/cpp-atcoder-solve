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
  ll n, m;
  cin >> n >> m;
  vector<string> s(n);
  int sum_sz_s = 0;
  REP(i, n) {
    cin >> s[i];
    sum_sz_s += SZ(s[i]);
  }
  set<string> t;
  REP(i, m) {
    string tt = input();
    t.insert(tt);
  }

  int mx_und = 16 - (n - 1) - sum_sz_s; // 追加できる"_"の個数

  // clang-format off
  function<void(string, int, int)> dfs = [&](string x, int bi, int und) -> void {
    if(SZ(x) > 16) return;

    if(bi == (1<<n)-1) { // すべてのs_iを使用済
      if(SZ(x) < 3) return;
      if(t.find(x) == t.end()) {
        cout << x << endl;
        exit(0);
      }
      return;
    }

    // bi: 既に使用したs_i ((bi >> k) & 1) がtrueならs_i をつかった
    // und: 追加できる"_"の個数
    REP(i, n) {
      if((bi >> i) & 1) continue; // すでに使っている
      if(bi == 0) { // 1文字列目
        dfs(s[i], (1<<i), und);
        continue;
      }
      string nx = x;
      nx.push_back('_');
      REP(j, und+1){ // j: 0 ~ und 追加する"_"の個数
        if(j > 0) nx.push_back('_');
        dfs(nx + s[i], (bi | (1<<i)), und-j);
      }
    }
  };

  dfs("", 0, mx_und);

  cout << -1 << endl;
}

/*-----------------------------------------------------------
-----------------------------------------------------------*/

#else // INCLUDED_MAIN

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