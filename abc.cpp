#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
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
  int n, m;
  cin >> n >> m;
  int t = n*m;

  if(m>1) t -= n*2;
  if(n>1) t -= m*2;

  if(n>1 && m > 1) t += 4;
  std::cout << t << std::endl;

  return 0;
}

