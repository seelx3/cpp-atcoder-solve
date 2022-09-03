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
  // REP(i, 10) cout << i << " \n"[i == 9];
  // REP(i, 5, 10) cout << i << " \n"[i == 9];
  // REP(i, 1, 9, 2) cout << i << " ";
  // cout << endl;
  // REPR(i, 10) cout << i << " \n"[i == 0];
  // REPR(i, 5, 10) cout << i << " \n"[i == 5];
  // REPR(i, 3, 10, 2) cout << i << " ";
  // cout << endl;

#ifdef LOCAL
  cout << "hello" << endl;
#endif

  int a = 12;
  ll b = 1234;
  deb(a, b);

  vector<ll> v = {1, 2, 3, 4, 5, 5, 5};
  deb(v);

  vector<vector<ll>> vv = {{1, 2, 3}, {2, 3, 4}, {5, 6, 7}};
  deb(vv);

  stack<int> sk;
  sk.push(23);
  sk.push(34);
  deb(sk);

  queue<int> qu;
  qu.push(123);
  qu.push(456);
  deb(qu);

  priority_queue<int> pq;
  pq.push(-1);
  pq.push(2345);
  pq.push(46);
  deb(pq);

  priority_queue<int, vector<int>, greater<int>> pqr;
  pqr.push(-1);
  pqr.push(2345);
  pqr.push(46);
  deb(pqr);

  deque<int> dq;
  dq.push_front(124);
  dq.push_back(432);
  dq.push_front(892);
  deb(dq);

  set<ll> st;
  st.insert(2456);
  st.insert(5345);
  deb(st);

  map<int, int> mp;
  mp[2839] = 34;
  mp[78] = 4982;
  deb(mp);
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

template <class T> vector<T> make_vec(size_t a) { return vector<T>(a); }
template <class T, class... Ts> auto make_vec(size_t a, Ts... ts) {
  return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}
// clang-format on

#ifdef LOCAL
#include <../.src/debug.hpp>
#define deb(...) debug::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define deb(...) (static_cast<void>(0))
#endif

#endif // INCLUDED_MAIN