#include <bits/stdc++.h>

using namespace std;

#define LIMIT 1000000
#define MOD 1000000007ll
#define INF 1e9
typedef long long ll;
typedef pair<ll, ll> ii;
int gcd(ll a, ll b) { return (b==0)?a:gcd(b, a%b); }
int lcm(ll a, ll b) { ll i=(a/gcd(a,b))*b; assert(i>0); return i; }
vector<int> primes;

int last6Digit(ll a){
  while(a%10 == 0) a/=10;
  return a%1000000;
}

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  bitset<LIMIT> bs; bs.set();

  for (int i = 2; i*i < LIMIT; ++i) {
    if(bs[i]){
      for (int j = i*i; j < LIMIT; j+=i) {
        bs[j] = 0;
      }
    }
  }
  for (int i = 2; i < LIMIT; ++i) {
    if(bs[i]) primes.push_back(i);
  }

  static ll pf[1000001]; memset(pf, 0, sizeof(pf[0])*1000000);

  for(int p : primes){
    if(p > 1000000) break;
    ll ind = p;
    while(ind <= 1000000){
      pf[ind] = p;
      ind *= p;
    }
  }

  static ll last[1000001];
  last[1] = 1; last[2] = 2;
  for (int i = 3; i < 1000001; ++i) {
    if(pf[i]){
      last[i] = last6Digit(pf[i]*last[i-1]);
    }
    else{
      last[i] = last[i-1];
    }
  }

  int n;
  while(cin >> n && n){
    std::cout << last[n]%10 << std::endl;
  }

  return 0;
}

