#include <bits/stdc++.h>

using namespace std;

#define LIMIT 10000010
#define MOD 1000000007ll
#define INF 1e9
typedef long long ll;
typedef pair<ll, ll> ii;
int gcd(ll a, ll b) { return (b==0)?a:gcd(b, a%b); }
int lcm(ll a, ll b) { ll i=(a/gcd(a,b))*b; assert(i>0); return i; }

vector<ll> primes;

ll numDiv(ll a) {
  ll ret = 1;
  for(int p : primes){
    if(p*p > a) break;
    if(a%p == 0){
      int power = 0;
      while(a%p == 0){
        a/=p;
        power++;
      }
      ret *= (power+1);
    }
  }
  if(a > 1) ret *= 2;
  return ret;
}

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  bitset<LIMIT> bs; bs.set();
  for(int i =2 ;i*i< LIMIT; i++){
    for (int j = i*i;bs[i] &&  j <LIMIT ; j+= i) bs[j] = 0;
  }

  for (int i = 2; i < LIMIT;++i ) {if(bs[i]) primes.push_back(i);}
  int t; cin >> t;
  while(t--){
    ll a, b;
    cin >> a >> b;

    ll i;
    ll c, ma = -1;
    for(i = a; i <= b; ++i){
      ll d = numDiv(i);
      if(d > ma){
        ma = d;
        c = i;
      }
    }
    printf("Between %lld and %lld, %lld has a maximum of %lld divisors.\n", a, b, c, ma);
  }


  return 0;
}

