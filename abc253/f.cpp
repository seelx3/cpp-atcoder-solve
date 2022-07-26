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

using S = long long;
using F = long long;

S op(S a, S b) { return -1; }
S e() { return 0; }
S mapping(F f, S x) { return f + x; }
F composition(F f, F g) { return f + g; }
F id() { return 0; }

int main() {
  ll N, M, Q;
  cin >> N >> M >> Q;
  auto qs = make_vec(Q, 4, 0LL);
  vector<ll> ans_col;

  ll cnt = 0;
  REP(i, Q) {
    int k = input();
    qs[i][0] = k;
    if (k == 1) {
      REP(j, 1, 4) cin >> qs[i][j];
    } else {
      REP(j, 1, 3) cin >> qs[i][j];
      if (k == 3) {
        ans_col.emplace_back(qs[i][2]);
        cnt++;
      }
    }
  }

  vector<ll> ans(cnt--); // 答え
  lazy_segtree<S, op, e, F, mapping, composition, id> seg(M + 5);

  // 3 i j の直前の
  // i行目に対するタイプ2のクエリ後の
  // タイプ3のクエリまでのタイプ1のクエリの結果(区間加算)が欲しい

  set<pair<int, int>> st; // 行、ans_id

  REPR(i, 0, Q) {
    int k = qs[i][0];
    if (k == 1) {
      seg.apply(qs[i][1], qs[i][2] + 1, qs[i][3]);
    } else if (k == 2) {
      ll rw = qs[i][1];
      ll ad = qs[i][2];
      while (true) {
        auto it = st.lower_bound({rw, -1});
        if (it == st.end()) break;
        if ((*it).first != rw) break;
        ans[(*it).second] += ad + seg.get(ans_col[(*it).second]);
        st.erase((*it));
      }
    } else if (k == 3) {
      ans[cnt] -= seg.get(qs[i][2]);
      st.insert(make_pair(qs[i][1], cnt--)); // 行とans_idをinsert
    }
  }

  // stに残った要素に対する処理
  for (auto it : st) {
    ans[it.second] += seg.get(ans_col[it.second]);
  }

  REP(i, SZ(ans)) cout << ans[i] << '\n';
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