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

ll N, Q;
vector<ll> X;
vector<vector<int>> tree;
vector<vector<ll>> LargeVertices;
vector<bool> seen;

void dfs(int u){ // u -> v
  seen[u] = true;
  vector<ll> tmpLargeVertices;
  tmpLargeVertices.push_back(X[u]);
  for(int i = 0; i < sz(tree[u]); i++) {
    int v = tree[u][i];
    if(seen[v]) continue;
    dfs(v);
    tmpLargeVertices.insert(tmpLargeVertices.end(), ALL(LargeVertices[v]));
  }
  sort(ALL(tmpLargeVertices), greater<>());
  for(int i = 0; i < min(20LL, sz(tmpLargeVertices)); i++) { 
    LargeVertices[u].push_back(tmpLargeVertices[i]); 
  } 
}

int main(){
  cin >> N >> Q;
  X.resize(N);
  tree.resize(N);
  LargeVertices.resize(N);
  seen.resize(N);

  for(int i = 0; i < N; i++) { cin >> X[i]; };
  for(int i = 0; i < N-1; i++) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }

  dfs(0);

  for(int i = 0; i < Q; i++) {
    int v, k;
    cin >> v >> k;
    cout << LargeVertices[--v][--k] << endl;
  }

  return 0;
}