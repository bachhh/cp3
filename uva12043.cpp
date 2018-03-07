#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
typedef int64_t ll;
typedef pair<ll, ll> ii;
int gcd(ll a, ll b) { return (b==0)?a:gcd(b, a%b); }
int lcm(ll a, ll b) { ll i=(a/gcd(a,b))*b; assert(i>0); return i; }

vector<int> primes;

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

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  static bitset<100001> sieve;
  sieve.set();

  for (int i = 2; i*i < 100001; ++i) {
    if(sieve[i]) {
      for(int j = i*i; j <= 100000; j+=i)
        sieve[j] = 0;
    }
  }

  primes.clear();
  for (int i = 2; i < 100000; ++i) {
    if (sieve[i]) primes.push_back(i);
  }


  int t; cin >> t;
  int a, b, k;

  ll g[100001];
  ll h[100001];

  g[0] = 0;
  h[0] = 0;

  for (int i = 1; i < 100001; ++i) {
    g[i] = numDiv(i);
    h[i] = sumDiv(i);
  }

  for (int i = 0; i < t; ++i) {
    cin >> a >> b >> k;
    ll x =0, y =0 ;
    for (int j = ceil((double)a/k)*k; j <= b; j+= k) {
      x += g[j];
      y += h[j];
    }
    std::cout << x << " " << y << std::endl;
  }

  return 0;
}

