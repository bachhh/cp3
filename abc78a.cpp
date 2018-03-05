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
  char x, y;

  cin >> x >> y;

  if(x < y){
    std::cout << '<' << std::endl;
  }
  else if (x > y){
    std::cout << '>' << std::endl;
  }
  else {
    std::cout << '=' << std::endl;
  }

  return 0;
}

