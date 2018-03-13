#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
#define MOD 1000000007ll
#define INF 1e9
typedef long long ll;
typedef pair<ll, ll> ii;
int gcd(ll a, ll b) { return (b==0)?a:gcd(b, a%b); }
int lcm(ll a, ll b) { ll i=(a/gcd(a,b))*b; assert(i>0); return i; }

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  ll n;
  bitset<10000011> bs;
  vector<ll> primes;
  bs.set();

  for(int i = 2; i*i <= 10000010; ++i){
    if(bs[i]){
      for(int j = i*i; j <= 10000010; j += i){
        bs[j ] = 0;
      }
    }
  }

  for(int i = 2; i <= 10000010; ++i) if(bs[i]) primes.push_back(i);

  //std::cout << primes.back() << std::endl;

  while(cin >> n && n){
    n = abs(n);
    ll mp = -1;
    int count = 0;
    for(ll p : primes){
      if(p*p > n) break;
      if(n%p == 0){
        count++;
        mp = max<ll>(mp, p);
        while(n%p == 0) n/= p;
      }
    }

    if (n > 1) {
      mp = n;
      count++;
    }
    if(count <= 1) mp = -1;

    std::cout << mp << std::endl;
  }

  return 0;
}

