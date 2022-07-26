#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)v.size()

vector<ll> Eratosthenes(const ll N) {
  vector<bool> is_prime(N + 1);
  for (int i = 0; i <= N; i++)
  {
    is_prime[i] = true;
  }
  vector<ll> P;
  for (ll i = 2; i <= N; i++)
  {
    if (is_prime[i])
    {
      for (ll j = 2 * i; j <= N; j += i)
      {
        is_prime[j] = false;
      }
      P.push_back(i);
    }
  }
  return P;
}

int main()
{
  ll n;
  cin >> n;

  vector<ll> primes = Eratosthenes(1000000);
  // set<ll> st;
  ll ans = 0;

  for(int i = 0; i < sz(primes); i++) {
    int j = i+1;
    ll p = primes[i];
    if(p > 100000) break;
    ll q = primes[j];
    if(p*q > n || p*q*q > n || p*q*q*q > n) break;
    ll u, v;
    while(p*q*q*q <= n) {
      // u = sz(st);
      // st.insert(p*q*q*q);
      // v = sz(st);
      // if(u == v) {
      //   cout << p << " " << q << endl;
      //   return 0;
      // }
      j++;
      q = primes[j];
      ans++;
    }
  }


  // cout << sz(st) << endl;
  cout << ans << endl;
  return 0;
}