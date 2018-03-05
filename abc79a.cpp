#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
typedef pair<int64_t, int64_t> ii;
typedef int64_t ll;
int gcd(ll a, ll b) { return (b==0)?a:gcd(b, a%b); }
int lcm(ll a, ll b) { ll i=(a/gcd(a,b))*b; assert(i>0); return i; }

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  cin >> s;
  int o = 1;

  for(int i = 1; i < 4; i++){
    if(s[i] == s[i-1]) o++;
    else o = 1;
    if(o >= 3){
      std::cout << "Yes" << std::endl;
      return 0;
    }
  }

  std::cout << "No" << std::endl;

  return 0;
}

