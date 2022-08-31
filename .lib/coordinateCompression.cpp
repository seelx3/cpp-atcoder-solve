/**
 * @brief 
 * @date 2022/02/27
 */

#include <bits/stdc++.h>
using namespace std;

template <class T> 
int compressedId(vector<T>& org, T num ){
  return lower_bound(org.begin(), org.end(), num) - org.begin();
}

int main() {
  // original vector
  vector<long long> org = {409, 100100100100, 200200200200, 100100100100100, 100100100100100100};

  // num -> index
  cout << compressedId(org, 200200200200LL) << endl;

  // index -> num
  cout << org[2] << endl;

  return 0;
}