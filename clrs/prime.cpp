#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
typedef pair<int64_t, int64_t> ii;
typedef int64_t ll;

void bfPrimeGen(vector<int64_t> &v, int64_t limit){
  v.push_back(2);
  v.push_back(3);
  for (int i = 3; i <= limit; ++i) {
    bool isPrime = true;
    for (int64_t prime : v){
      if(prime*prime > i) break;
      if (i % prime == 0){
        isPrime = false;
        break;
      }
    }
    if (isPrime) v.push_back(i);
  }
}

void sieveOfEras(vector<int64_t> v, int64_t limit){}

int64_t power(int64_t a, int64_t b, int mod){
  int64_t output = 1;
  a %= mod;

  while(b>0){
    if (b&1) {
      output = (output*a)%mod;
    }
    b /= 2;
    a = (a*a)%mod;
  }
  return output;
}

bool millerTest(int x, int d){

  int a= 2 +rand()%( x-4 );
  int y = power(a, d, x);

  if ( y == 1 || y == x-1){
    return true;
  }

  while(d != x-1){
    y = (y*y) %x;
    d *= 2;
    if(y==1) return false;
    if (y == x-1) return true;
  }
  return false;
}

bool primeTest(int64_t x, int k){

  if(x<=1) return false;
  if (x == 2 || x == 3) return true;
  if (x%2==0) return false;

  int64_t d = x-1;
  while(d%2 == 0){
    d /= 2;
  }

  for (int i = 0; i < k; ++i) {
    if(millerTest(x, d) == false) return false;
  }
  return true;

}

ll primes[100];
ll numPF(ll n){
  int i = 0;
  ll PF = primes[i];
  ll ans = 0;
  while(PF*PF <= n){
    while(n%PF == 0){
      n /= PF;
      ans++;
    }
    PF = primes[++i];
  }
  if(n != 1) ans++;
  return ans;
}

ll numDiffPF(ll n){
  ll i = 0, PF = primes[i], ans = 0;
  while(PF*PF <= n){
    bool flag = false;
    while(n%PF == 0){
      n /= PF;
      flag = true;
    }
    if(flag) ans++;
    PF = primes[++i];
  }
  if (n!=1) ans++;
  return ans;
}

ll sumPF(ll n){
  ll i = 0, PF = primes[i], ans = 0;
  while(PF*PF <= n){
    while(n%PF == 0){
      n /= PF;
      ans += PF;
    }
    PF = primes[++i];
  }
  if (n != 1) ans += n;
  return ans;
}

ll numDiv(ll n){
  ll i = 0, PF = primes[i], ans = 1;
  while(PF*PF <= n){
    ll p = 0;
    while(n%PF == 0){
      n /= PF;
      p++;
    }
    ans *= (p+1);
    PF = primes[++i];
  }
  if (n != 1) ans *= 2;
  return ans;
}

ll sumDiv(ll n){
  ll ans = 1, i = 0, PF = primes[i];
  while(PF*PF <= n){
    ll power = 0;
    while(n%PF == 0){
      n /= PF;
      power++;
    }
    ans *= ((ll)pow((double)PF, power+1)-1)/(PF-1);
    PF = primes[i++];
  }
  if (n != 1){
    ans *= ((ll)pow((double)n, 2.0)-1)/(n-1);
  }
  return ans;
}

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  for (int i = 0; i < 100; ++i) {
    printf("%d %d\n", i, primeTest(i, 10));
  }

  return 0;
}

