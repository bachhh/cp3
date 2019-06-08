#include <bits/stdc++.h>

using namespace std;

#define LIMIT 10000010
#define MOD 1000000007ll
#define INF 1e9
typedef long long ll;
typedef pair<ll, ll> ii;
int gcd(ll a, ll b) { return (b==0)?a:gcd(b, a%b); }
int lcm(ll a, ll b) { ll i=(a/gcd(a,b))*b; assert(i>0); return i; }

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;

  bitset<LIMIT> bs; bs.set();
  for (int i = 2; i*i < LIMIT; ++i) {
    for (int j = i*i; j < LIMIT &&bs[i]; j+=i) { bs[j] = 0;}
  }
  vector<ll> primes;
  for (int i = 2; i < LIMIT; ++i) {if(bs[i]) primes.push_back(i); }

  for (int i = 0; i < t; ++i) {
    int a, c;
    cin >> a >> c;
    if(gcd(a, c) != a){
      std::cout << "NO SOLUTION" << std::endl;
    }
    else{
      ll ans = 1;
      for(int p : primes){
        if(p*p > a) break;
        if(a%p == 0){
          int power1 = 0, power2 = 0;
          while(a%p== 0){power1++; a /= p;}
          while(c%p== 0){power2++; c /= p;}
          if(power1 < power2){
            ans *= ll(pow(p, power2));
          }
        }
      }

      if( c > 1) ans *= c;
      if( a > 1){
        if(c%a == 0 && (c/a)%a != 0 )
          ans /= a;
      }
      std::cout << ans << std::endl;
    }
  }

  return 0;
}

