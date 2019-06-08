#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
#define MOD 1000000007
typedef long long ll;
typedef pair<ll, ll> ii;
int gcd(ll a, ll b) { return (b==0)?a:gcd(b, a%b); }
int lcm(ll a, ll b) { ll i=(a/gcd(a,b))*b; assert(i>0); return i; }


int power(int a, ll b){
  int ret =1;
  while(b){
    if ( b & 1) ret = ( ll(ret) * a  )% MOD;
    a = (ll(a)* a)%MOD;
    b>>=1;
  }
  return ret;
}

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  ll n; cin >> n;

  ll o = 1;
  ll o2 = 1;

  ll base = 4;
  ll base2 = 2;

  ll i = n;
  while(i){
    if(i&1){
      o = (o*base)%MOD;
      o2 = (o2*base2)%MOD;
    }
    base = (base*base)%MOD;
    base2 = (base2*base2)%MOD;
    i >>= 1;
  }

  std::cout << ( power(2, n)+power(4, n) )/2 << std::endl;

  o = ((o+o2))/2;

  std::cout << o << std::endl;


  return 0;
}

