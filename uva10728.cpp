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
int mu(int n){
  if(n == 1) return 1;
  int pfcount = 0;
  for(int p : primes){
    if(p*p > n) break;
    if(n%p == 0){
      pfcount++;
      n /= p;
      if(n%p == 0) return 0;
    }
  }
  if(n > 1) pfcount++;
  if(pfcount%2 == 0) return 1;
  return -1;
}

//  ***** MAIN *****
int main(){

  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  bitset<PLIMIT> bs; bs.set();

  for (int i = 2; i*i < PLIMIT; ++i) {
    for (int j = i*i; bs[i] && j < PLIMIT; j+= i) {
      bs[j] = 0;
    }
  }
  for (int i = 2; i < PLIMIT; ++i) {
    if(bs[i]) primes.push_back(i);
  }

  static int precal[1000001];
  static int prefix[1000001];
  prefix[1] = mu(1);

  for (int i = 2; i < 1000001; ++i) {
    precal[i] = mu(i);
    prefix[i] = prefix[i-1] + precal[i];
  }

  int n;

  while(cin >> n && n){
    printf("%8d %8d %8d\n",n, precal[n], prefix[n]);
  }

  return 0;
}

