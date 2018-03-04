#include <bits/stdc++.h>

using namespace std;

#define LIMIT 10000009
typedef pair<int64_t, int64_t> ii;
typedef long long LL;
typedef long L;
int gcd(LL a, LL b) { return (b==0)?a:gcd(b, a%b); }
int lcm(LL a, LL b) { LL i=(a/gcd(a,b))*b; assert(i>0); return i; }

vector<L> primes;
int ss = 10000010;
bool isPrime(LL a){
  if (a<ss){
    return *lower_bound(primes.begin(), primes.end(), a) == a;
  }
  else {
    bool flag = true;
    for(auto p : primes){
      if (p*p > a || !flag) break;
      if (a%p == 0) flag = false;
    }
    return flag;
  }
}
//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  bitset<10000010> sieve; sieve.set();
  for (LL i = 2; i*i < ss; ++i) {
    if(sieve[i]){
      for(int j = i*i; j < ss; j +=i ) sieve[j] = 0;
    }
  }

  for(int i = 2; i <= ss; ++i) {
    if (sieve[i]) primes.push_back(i);
  }

  LL l, r;

  while(cin >> l >> r){

    LL mind = ss, maxd = 0;
    LL x = 0, y, a, b;
    LL lastPrime = 0;
    for(LL i = l; i <= r; ++i){
      if(isPrime(i)){
        if(lastPrime) {
          if (i-lastPrime < mind){
            x = lastPrime; y  = i;
            mind = i-lastPrime;
          }

          if(i-lastPrime > maxd){
            a = lastPrime; b = i;
            maxd = i-lastPrime;
          }
        }
        lastPrime = i;
      }
    }

    if(x == 0){
      puts("There are no adjacent primes.");
    }
    else{
      printf("%lld,%lld are closest, %lld,%lld are most distant.\n", x, y, a, b);
    }
  }

  return 0;
}

