#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
#define PLIMIT 10000010
#define MOD 1000000007ll
#define INF 1e9
typedef long long ll;
typedef pair<ll, ll> ii;
int gcd(ll a, ll b) { return (b==0)?a:gcd(b, a%b); }
int lcm(ll a, ll b) { ll i=(a/gcd(a,b))*b; assert(i>0); return i; }

vector<int> primes;
int numPF(int n){
  int ret = 0;
  for(auto p : primes){
    if(p*p > n) break;
    if(n%p == 0){
      ret++;
      while(n%p == 0){ n/= p; }
    }
  }
  if(n > 1) ret++;
  return ret;
}

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  bitset<PLIMIT> bs; bs.set();
  for (int i = 2; i*i < PLIMIT; ++i) {
    for (int j = i*i; bs[i] && j < PLIMIT; j+=i) {
      bs[j] = 0;
    }
  }

  for (int i = 2; i < PLIMIT; ++i) { if(bs[i]) primes.push_back(i); }

  int s;
  while(cin >> s && s){
    std::cout << s << " : " << numPF(s) << std::endl;
  }

  return 0;
}

