#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
typedef pair<int64_t, int64_t> ii;
typedef int64_t ll;
int gcd(ll a, ll b) { return (b==0)?a:gcd(b, a%b); }
int lcm(ll a, ll b) { ll i=(a/gcd(a,b))*b; assert(i>0); return i; }

bitset<1000002> sieve;
//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);


  sieve.set();
  sieve[0] = 0;
  sieve[1] = 0;

  for(ll i =2; i <= 1000000; ++i){
    if (sieve[i]){
      for(ll j = i*i; j > 0 && j <= 1000000; j+=i){
        //std::cout << i << "|" << j << std::endl;
        sieve[j] = 0;
      }
    }
  }
  vector<int> primes;

  for (int i = 0; i <= 1000000; ++i) {
    if(sieve[i])primes.push_back(i);
  }

  int n;

  while(cin >> n && n > 0){
    for(int p1 : primes){
      if (*lower_bound(primes.begin(), primes.end(), n-p1) == n-p1){
        printf("%d = %d + %d\n", n, p1, n-p1);
        break;
      }
    }
  }

  return 0;
}

