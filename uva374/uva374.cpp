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

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  ll b, p, m;
  while(cin >> b>> p >> m ){
    ll r = 1;
    b %= m;
    while(p){
      if (p&1){
        r = ( r*b )%m;
      }
      p >>=1;
      b = (b*b)%m;
    }
    std::cout << r << std::endl;
  }

  return 0;
}

