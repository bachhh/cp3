#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
typedef int64_t ll;
typedef pair<ll, ll> ii;
int gcd(ll a, ll b) { return (b==0)?a:gcd(b, a%b); }
int lcm(ll a, ll b) { ll i=(a/gcd(a,b))*b; assert(i>0); return i; }


//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int q; cin >> q;

  bitset<100001> sieve;
  sieve.set();
  for(int i = 2; i*i <= 100000; ++i){
    if (sieve[i]){
      for (int j = i*i; j <= 100000; j += i) {
        sieve[j] = 0;
      }
    }
  }
  sieve[0] = 0;
  sieve[1] = 0;


  ll counter[100001];
  memset(counter, 0, sizeof(counter[0])*100001);

  for(int i = 1; i <= 100000; ++i){

    counter[i] = counter[i-1];
    if(i%2 && sieve[i] && sieve[(i+1)/2]) counter[i]++;
  }


  for (int i = 0; i < q; ++i) {
    int l, r;
    cin >> l >> r;
    std::cout << counter[r] - counter[l-1] << std::endl;
  }

  return 0;
}

