#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
typedef pair<int64_t, int64_t> ii;
typedef int64_t ll;
int gcd(ll a, ll b) { return (b==0)?a:gcd(b, a%b); }
int lcm(ll a, ll b) { ll i=(a/gcd(a,b))*b; assert(i>0); return i; }

ll eulerPhi(vector<int> primes, ll n){
  ll ret = n;
  for(int p : primes){
    if((ll)p*p > n) break;
    if(n%p == 0){
      while(n%p == 0) n /= p;
      ret *= (1.0 - (1.0)/ (float) p);
    }
  }
  if(n>1) ret *= (1.0 - (1.0)/(float)n);
  return ret;
}

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  int c[50001];
  bitset<100000> sieve;
  sieve.set();
  for(int i = 2; i <= 1000; ++i ){
    if(sieve[i]){
      for (int j = i*i; j <= 100000; j+= i) {
        sieve[j] = 0;
      }
    }
  }

  vector<int> primes;
  for(int i = 2; i <= 1000000; i++)
    if(sieve[i]) primes.push_back(i);

  memset(c, 0, sizeof(c[0])*50001);
  c[1] = 1;

  for (int i = 2; i <= 50000; ++i) {
    ll o = eulerPhi(primes, i);
    c[i] = c[i-1] + o*2;
  }

  while(cin >> n && n){
    std::cout << c[n] << std::endl;
  }

  return 0;
}

