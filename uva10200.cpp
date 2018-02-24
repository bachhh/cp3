#include <bits/stdc++.h>

using namespace std;

#define LIMIT 10000 *(10000+1) + 41
typedef pair<int64_t, int64_t> ii;
typedef int64_t ll;

bitset<LIMIT> bs;
vector<ll> primes;

void sieve(ll bound){
  //primes.clear();
  bs.set();
  bs.reset(0);
  bs.reset(1);
  for(ll i = 2; i <= bound; ++i){
    if (bs[i]){
      for(ll j = i*i; j <= bound; j += i){
        bs[j] = false;
      }
      //primes.push_back(i);
    }
  }
}



//  ***** MAIN *****
int main(){

  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  sieve(LIMIT);
  ll a, b;

  while(cin >> a>>b){
    ll output = 0;
    for(ll i = a; i <= b; ++i ){
      ll n = i*(i+1) + 41;
      if (bs[n]){
        output++;
      }
    }
    double percent = output/(double)(b-a+1);
    printf("%.2f\n", percent*100);
  }
  return 0;
}

