#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
#define PLIMIT 10000010
#define MOD 10000000000ll
#define INF 1e9

typedef long long ll;
typedef pair<ll, ll> ii;

int gcd(ll a, ll b) { return (b==0)?a:gcd(b, a%b); }
int lcm(ll a, ll b) { ll i=(a/gcd(a,b))*b; assert(i>0); return i; }

ll P(ll n, ll m){
  ll ret = 1;
  // n!/ (n-m)!
  for (ll i = n-m+1; i <= n; ++i) {
    ret *= i;
    while(ret%10 == 0) ret/=10;
    ret %= MOD;
  }
  return ret%10;
}

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  ll n, m;
  while(cin >> n >> m){
    std::cout << P(n, m) << std::endl;
  }

  return 0;
}

