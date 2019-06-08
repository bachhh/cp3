#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
#define PLIMIT 1000001
#define MOD 1000000007ll
#define INF 1e9
typedef long long ll;
typedef pair<ll, ll> ii;
int gcd(ll a, ll b) { return (b==0)?a:gcd(b, a%b); }
int lcm(ll a, ll b) { ll i=(a/gcd(a,b))*b; assert(i>0); return i; }

int x2;
vector<int> primes;

int maxPF(int n){
  int ret = -1;
  for(int p : primes){
    if(p*p > n) break;
    if(n%p == 0){
      ret = max(ret, p);
      while(n%p == 0) n/= p;
    }
  }
  if(n> 1) ret = max(ret, n);
  return ret;
}

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  bitset<PLIMIT> bs; bs.set();
  for (int i = 2; i*i < PLIMIT; ++i) {
    for (int j = i*i; bs[i] && j < PLIMIT; j += i) {
      bs[j] = 0;
    }
  }

  for (int i = 2; i < PLIMIT; ++i) {
    if(bs[i]) primes.push_back(i);
  }

  cin >> x2;

  int px2 = maxPF(x2);
  int o = INT_MAX;
  for(int x1 = x2 - px2+1; x1 <= x2; ++x1){
    if(bs[x1]) continue;
    int px1 = maxPF(x1);
    //std::cout <<x1<<"|"<< px1 << std::endl;
    o = min(o, x1-px1+1);
  }
  std::cout << o << std::endl;

  return 0;
}

