#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
typedef int64_t ll;
typedef pair<ll, ll> ii;
int gcd(ll a, ll b) { return (b==0)?a:gcd(b, a%b); }
int lcm(ll a, ll b) { ll i=(a/gcd(a,b))*b; assert(i>0); return i; }

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  ll x, y; cin >> x >> y;

  int o = 0;


  while(x <= y){
    o++;
    x *= 2;
  }

  std::cout << o << std::endl;

  //std::cout << n +1 << std::endl;

  return 0;
}

