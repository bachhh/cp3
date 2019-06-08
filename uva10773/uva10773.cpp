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
  int tc; cin >> tc;

  for (int i = 1; i <= tc; ++i) {
    int d, v, u;
    cin >> d >> v >> u;
    if(v == 0 || u == 0 || u<=v){
      printf("Case %d: can't determine\n", i);
    }
    else{
      double p = abs(double(d)/u - d/(sqrt(u*u - v*v)));
      printf("Case %d: %.3lf\n",i, p);
    }
  }

  return 0;
}

