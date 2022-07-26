#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) v.begin(),v.end()
#define sz(v) (int)v.size()

int main(){
  string s;
  cin >> s;

  if(sz(s)==1) cout << s << s << s << s << s << s << endl;
  else if(sz(s)==2) cout << s << s << s << endl;
  else if(sz(s)==3) cout << s << s << endl;
}