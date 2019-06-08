#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef pair<int64_t, int64_t> ii;
typedef int64_t ll;
int gcd(ll a, ll b) { return (b==0)?a:gcd(b, a%b); }
int lcm(ll a, ll b) { ll i=(a/gcd(a,b))*b; assert(i>0); return i; }

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  ll a, b;  cin  >> a >> b;

  a %= MOD;
  b %= MOD;

  ll x = ((b*(b-1)%MOD)/2)%MOD;


  ll y = ((((a*(a+1))%MOD)*b)/2)%MOD + a;

  y %= MOD;

  ll output = (x*y)%MOD;

  std::cout << output << std::endl;


  return 0;
}

