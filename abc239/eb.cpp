/**
 * @brief abc239_e eulerTour method w/ segTree
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)
#define ALL(v) v.begin(),v.end()
#define sz(v) (ll)v.size()
const ll INF = 1e18;
// const ll MOD = 998244353;
const ll MOD = 1000000007;
ll dx[] = {1, 0, -1, 0};
ll dy[] = {0, 1, 0, -1};
const double PI = acos(-1.0);

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

  void change(int i, T x) {
    i += n - 1;
    data[i] = update(data[i], x);
    while(i > 0) {
      i = (i-1) / 2;
      data[i] = operation(data[i*2 + 1], data[i*2 + 2]);
    }
  }

  T query(int a, int b) {
    return _query(a, b, 0, 0, n);
  }

  T operator[](int i) {
    return data[i+n-1];
  }

};

int main(){
  int N, Q;
  cin >> N >> Q;
  vector<ll> X(N);
  for(int i = 0; i < N; i++) { cin >> X[i]; }

  vector<vector<int>> G(N);
  for(int i = 0; i < N-1; i++) {
    ll a, b;
    cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  vector<int> in(N, -1), out(N);
  vector<int> visit, visit_x;

  auto DFS = [&](auto dfs, int u) -> void {
    in[u] = sz(visit);
    visit.push_back(u);
    visit_x.push_back(X[u]);
    for(auto v : G[u]) {
      if(in[v] != -1) continue;
      dfs(dfs, v);
    }
    out[u] = sz(visit);
    visit.push_back(u);
    visit_x.push_back(-X[u]);
  };

  DFS(DFS, 0);

  // cout << sz(visit_x) << endl;
  // for(int i = 0; i < sz(visit_x); i++) {
  //   cout << i << " : " << visit_x[i] << endl;
  // }

  SegTree<pair<ll, int>> segT(
    sz(visit_x), 
    make_pair(-INF, 0), 
    [](pair<ll, int> a, pair<ll, int> b){ return max(a, b); }, 
    [](pair<ll, int> a, pair<ll, int> b){ return b; }
  );

  for(int i = 0; i < sz(visit_x); i++) {
    segT.change(i, {visit_x[i], i});
  }

  for(int q = 0; q < Q; q++) {
    int v, k;
    cin >> v >> k;
    v--;
    vector<int> tmp;
    for(int i = 0; i < k; i++) {
      auto p = segT.query(in[v], out[v]+1);
      if(i == k-1) cout << p.first << endl;
      tmp.push_back(p.second);
      segT.change(p.second, {-p.first, p.second});
    }
    for(auto it : tmp) {
      segT.change(it, {-segT[it].first, it});
    }
  }

  return 0;
}