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
ll eulerPhi(ll n){
  double ret = n;
  for(int p : primes){
    if((ll)p*p > n) break;
    if(n%p == 0){
      while(n%p == 0) n /= p;
      ret *= (1.0 - (1.0)/ (float) p);
    }
  }
  if(n>1) ret *= (1.0 - (1.0)/(float)n);
  return (ll)ceil(ret);
}

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  primes.clear();
  bitset<LIMIT> bs; bs.set();
  for (int i = 2; i*i < LIMIT; ++i) {
    for (int j = i*i; j < LIMIT && bs[i]; j += i) {bs[j] = 0; }
  }

  for (int i = 2; i < LIMIT; ++i) {if(bs[i]) primes.push_back(i); }

  ll n;
  while(cin >> n && n){
    std::cout << eulerPhi(n) << std::endl;
  }

  return 0;
}

