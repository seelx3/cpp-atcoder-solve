#ifndef INCLUDED_MAIN
#define INCLUDED_MAIN

#include __FILE__

int main() {
  string hello = "Hello World!";
  cout << hello << endl;
}

/*-----------------------------------------------------------
-----------------------------------------------------------*/

#else // INCLUDED_MAIN

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(), v.end()
#define sz(v) (int)(v.size())

#endif // INCLUDED_MAIN