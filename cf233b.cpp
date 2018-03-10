#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
typedef long long ll;
typedef pair<ll, ll> ii;
int gcd(ll a, ll b) { return (b==0)?a:gcd(b, a%b); }
int lcm(ll a, ll b) { ll i=(a/gcd(a,b))*b; assert(i>0); return i; }

ll compute(ll x, ll s ){
  return x*x + s*x;
}

ll sumOfDigit(ll x){
  int o =0 ;
  while(x){ o+= x%10; x/=10;}
  return o;
}

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  ll n; cin >> n;

  for (int s = 1; s <= 9*17; ++s) {

    ll l = 0, h = ceil(sqrt(n))*2;
    ll ret, m;
    while(l <= h){
      m = l + (h-l)/2;
      ret = compute(m, s);
      if(ret < n){
        l = m+1;
      }
      else if(ret > n){
        h = m-1;
      }
      else {
        break;
      }
    }

    if(sumOfDigit(m) == s && ret == n){
      std::cout << m << std::endl;
      return 0;
    }
  }
  std::cout << -1 << std::endl;

  return 0;
}

