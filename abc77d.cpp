#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
typedef int64_t ll;
typedef pair<ll, ll> ii;
int gcd(ll a, ll b) { return (b==0)?a:gcd(b, a%b); }
int lcm(ll a, ll b) { ll i=(a/gcd(a,b))*b; assert(i>0); return i; }

ll sumDigit(int a){
  ll ret = 0;
  while(a>0){
    ret += a%10;
    a /= 10;
  }
  return ret;
}

//  ***** MAIN *****
int main(){

  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  ll k; cin >> k;
  ll o = INT64_MAX;

  for (ll i = 1; i < k; ++i){
    ll d= sumDigit(i*k);
    //printf("%ld %ld\n", i, d);
    o = min<ll>(o, d);
  }

  std::cout << o << std::endl;

  return 0;
}

