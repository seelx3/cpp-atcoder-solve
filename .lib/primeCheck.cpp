/**
 * @brief determine whether or not an integer less than or equal
 *        to N is a prime number.
 * @date 2022/02/22
 */

#include <bits/stdc++.h>
using namespace std;

vector<bool> prime_numbers(long long n)
{
  vector<bool> ret(n + 1, true);
  ret[0] = false;
  ret[1] = false;
  long long m = 2;
  for (int i = 2; i <= n; i++)
  {
    if (ret[i]) {
      for (int j = 2; i * j <= n; j++) {
        ret[i * j] = false;
      }
    }
  }
  return ret;
}

// 素数列挙
int main()
{
  long long n;
  cin >> n;
  vector<bool> vb = prime_numbers(n);
  vector<long long> primes;
  for (int i = 2; i < (int)vb.size(); i++) {
    if(vb[i]) primes.push_back(i);
  }

  cout << "{";
  for(int i = 0; i < (int)primes.size(); i++) {
    cout << primes[i] << ",}"[i==(int)primes.size()-1];
  }
}