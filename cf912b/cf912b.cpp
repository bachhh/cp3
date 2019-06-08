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
int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  ll n, k; cin >> n >> k;
  int maxbit = 0;

  for (int i = 0; i <= 61; ++i) {
    if(n & ((ll)1<<i) ) maxbit = i;
  }

  ll t = ((ll)1<<maxbit+1)-1;
  t = max<ll>(n, t);
  std::cout << t << std::endl;

  return 0;
}

