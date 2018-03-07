#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
typedef pair<int64_t, int64_t> ii;
typedef int64_t ll;

ll primes[100];

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

long long powerMod(int a, int b, int mod){
  long long output = 1;
  a %= mod;

  while(b>0){
    if (b%2 == 1) {
      output = (output*a)%mod;
    }
    b /= 2;
    a = (a*a)%mod;
  }
  return output%mod;
}

long long mulMod(long long a, long long b, long long mod){
  long long output = 0;
  a %= mod;
  while(b > 0){
    if (b%2){
      output = (a+output)%mod;
    }
    output = (output*2)%mod;
    b = b >> 1;
  }
  return output % mod;
}

bool millerRabin(long long p, int d){
  if (p<2) return false;
  if (p> 2 && p&1) return false;
  long long s = p-1;
  while(s%2 == 0) s/= 2;

  for (int i = 0; i < d; ++i) {

    long long a = rand() % (p-1)+1;
    long long temp = s;
    // a^s mod p
    long long mod = powerMod(a, temp,p );
    if (mod == 1) continue;

    while(temp < p-1){
      // repeated squaring of (a^s) mod p
      mod = mulMod(mod, mod, p);
      temp *= 2;
      if (mod == 1 || mod == -1) break;
    }

    if (temp == p-1 && mod != 1){
      return false;
    }

  }

  return true;
}


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

ll numDiv(ll N) {
  ll PF_idx = 0, PF = primes[PF_idx], ans = 1;
  // start from ans = 1
  while (PF * PF <= N) {
    ll power = 0;
    // count the power
    while (N % PF == 0) { N /= PF; power++; }
    ans *= (power + 1);
    // according to the formula
    PF = primes[++PF_idx];
  }
  if (N != 1) ans *= 2;
  // (last factor has pow = 1, we add 1 to it)
  return ans;
}

ll sumDiv(ll N) {
  ll PF_idx = 0, PF = primes[PF_idx], ans = 1;
  // start from ans = 1
  while (PF * PF <= N) {
    ll power = 0;
    while (N % PF == 0) { N /= PF; power++; }
    ans *= ((ll)pow((double)PF, power + 1.0) - 1) / (PF - 1);
    PF = primes[++PF_idx];
  }
  if (N != 1) ans *= ((ll)pow((double)N, 2.0) - 1) / (N - 1); // last
  return ans;
}

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
  for (int i = 0; i < 100; ++i) {
    printf("%d %d\n", i, millerRabin(i, 10));
  }

  return 0;
}

