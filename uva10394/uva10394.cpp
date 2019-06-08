#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
typedef pair<int64_t, int64_t> ii;
typedef int64_t ll;
int gcd(ll a, ll b) { return (b==0)?a:gcd(b, a%b); }
int lcm(ll a, ll b) { ll i=(a/gcd(a,b))*b; assert(i>0); return i; }

bitset<10000010> sieve;
vector<ii> twins;
vector<ll> primes;


//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;

  sieve.set();

  for (ll i = 2; i <= 10000009; ++i) {
    if(i*i < 10000009 && sieve[i]){
      for (int j = i*i; j <= 10000009; j+= i) {
        sieve[j] = 0;
      }
    }
  }

  for(ll i = 2; i <= 10000007; ++i){
    if(sieve[i] ) {primes.push_back(i);
      if (sieve[i+2]) twins.push_back(ii(i, i+2));
    }
  }

  for(ll low = 10000011; low < 20000000; low+= sieve.size()){
    sieve.set();
    ll high = min<ll>(20000000, low + sieve.size()-1);

    for(auto p : primes){
      if(p*p > high) break;
      ll lowmin = low/p*p;
      if(lowmin < low) lowmin += p;
      for(ll j = lowmin; j <= high; j += p){
        sieve[j-low] = false;
      }
    }

    for(ll i = 0; i <= 10000009; ++i){
      if(sieve[i] ) {primes.push_back(i+low);
        if (sieve[i+2]) twins.push_back(ii(i+low, low+i+2));
      }
    }

  }


  while(cin >> n){
    printf("(%ld, %ld)\n", twins[n-1].first, twins[n-1].second);
  }

  return 0;
}

