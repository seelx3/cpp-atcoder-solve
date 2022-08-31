/**
 * @brief abstract segment tree
 * 区間クエリ, 1点更新
 * @date 2022/02/27
 * 
 * ~~ problems ~~
 * abc239_e eulerTour method w/ segTree https://atcoder.jp/contests/abc239/tasks/abc239_e
 * DSL_2_A https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_A
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)
#define ALL(v) v.begin(),v.end()
#define sz(v) (ll)v.size()
const ll INF = 1e18;

/*---------------------------
---------------------------*/

template <class T>
class SegTree {
  int n;
  vector<T> data;
  T def;
  function<T(T, T)> operation;
  function<T(T, T)> update;

  T _query(int a, int b, int k, int l, int r) {
    if(r <= a || b <= l) return def;
    if(a <= l && r <= b) return data[k];
    else {
      T c1 = _query(a, b, 2*k+1, l, (l+r)/2);
      T c2 = _query(a, b, 2*k+2, (l+r)/2, r);
      return operation(c1, c2);
    } 
  }

  public:
  SegTree(size_t _n, T _def, function<T(T, T)> _operation, function<T(T, T)> _update)
    : def(_def), operation(_operation), update(_update) {
    n = 1;
    while(n < _n) n *= 2;
    data = vector<T>(2*n - 1, def);
  }

  void upDate(int i, T x) {
    i += n - 1;
    data[i] = update(data[i], x);
    while(i > 0) {
      i = (i-1) / 2;
      data[i] = operation(data[i*2 + 1], data[i*2 + 2]);
    }
  }

  T get(int a, int b) {
    return _query(a, b, 0, 0, n);
  }

  T operator[](int i) {
    return data[i+n-1];
  }
};

/*---------------------------
---------------------------*/

int main(){
  int n, q;
  cin >> n >> q;
  SegTree<ll> st(n, (1LL << 31) - 1, [](ll a, ll b){ return min(a, b); }, [](ll a, ll b){ return b; }); // min
  // SegTree<ll> st(n, -((1LL << 31) - 1), [](ll a, ll b){ return max(a, b); }, [](ll a, ll b){ return b; }); // max
  // SegTree<ll> st(n, 0, [](ll a, ll b){ return a+b; }, [](ll a, ll b){ return a+b; }); // sum
  for(int i = 0; i < q; i++) {
    int c, x, y;
    cin >> c >> x >> y;
    if(c == 0) {
      st.upDate(x, y);
    } else {
      cout << st.get(x, y+1) << endl;
    }

    // debug
    // for(int i = 0; i < n; i++) {
    //   cout << st[i] << " \n"[i==n-1];
    // }
  }

  return 0;
}

/*---------------------------
example min
3 5
0 0 1
0 1 2
0 2 3
1 0 2
1 1 2
---------------------------*/