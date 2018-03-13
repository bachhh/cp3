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
ll fact(ll i){
  if(i == 0) return 1;
  return fact(i-1)*i;
}

bool solve(ll n, ll m){
  for(int p : primes){
    if(ll(p)*p > m)break;
    if(m%p==0){
      int power1 = 0;
      while(m %p ==0){
        power1++;
        m /= p;
      }
      ll tmp = p;
      int power2 =0;
      while(tmp <= n){
        power2 += n/tmp;
        tmp *= p;
      }
      if(power1 > power2){
        return false;
      }
    }
  }

  // left over prime, n! does not reach m
  if(m > 1 && n < m){
    return false;
  }
  return true;
}

//  ***** MAIN *****
int main(){

  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  ll n, m;
  bitset<LIMIT> bs; bs.set();

  for(int i =2; i*i < LIMIT; ++i){
    if(bs[i]){
      for (int j = i*i; j < LIMIT; j += i) {
        bs[j] = 0;
      }
    }
  }
  for (int i = 2; i < LIMIT; ++i) {
    if(bs[i]) primes.push_back(i);
  }

  while(cin >> n >> m){
    if(solve(n, m)){
      printf("%lld divides %lld!\n", m, n);
    }
    else{
      printf("%lld does not divide %lld!\n", m, n);
    }

  }
   return 0;
}

