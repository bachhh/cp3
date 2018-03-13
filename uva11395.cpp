#include <bits/stdc++.h>

using namespace std;

#define LIMIT 10000010
#define MOD 1000000007ll
#define INF 1e9
typedef long long ll;
typedef pair<ll, ll> ii;
int gcd(ll a, ll b) { return (b==0)?a:gcd(b, a%b); }
int lcm(ll a, ll b) { ll i=(a/gcd(a,b))*b; assert(i>0); return i; }

vector<int> primes;

ll sigma(ll n){

  ll ret = 1;
  for(int p : primes){
    if(ll(p)*p > n) break;
    if(n%p == 0){
      int power = 0;
      while(n%p == 0 ){
        n/= p;
        power++;
      }
      ret *= ((ll)(pow((double)p, power+1) - 1))/(p-1);
    }
  }
  if (n > 1) ret *= ((ll)(pow((double)n, 2) - 1))/(n-1);
  return ret;
}

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  ll nmax = 1000000000001;

  bitset<LIMIT> bs; bs.set();
  for (int i = 2; i*i < LIMIT; ++i) {
    for (int j = i*i; bs[i] &&j<LIMIT;j+=i){bs[i] =0;}
  }

  for(int i = 2; i< LIMIT; ++i) primes.push_back(i);

  map<ll, ll> sig; sig[1] = 1;


  std::clock_t start;
  double dur;
  start = clock();

  map<ll, int> even; even[1] = 0;
  for (ll i = 2; i < nmax; ++i) {
    //std::cout << i << std::endl;
    if(sig[i] != 0){
      even[i] = even[i-1];
      if(sig[i] % 2 == 0) even[i]++;
    }
  }

  ll n;
  while(cin >> n && n){
  }


  dur= ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
  std::cout<< "printf: "<< dur<<'\n';
  return 0;
}

