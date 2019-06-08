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
  ll a, b;
  cin >> a >> b;

  while(true){
    if(a==0 || b==0){
      break;
    }
    if (a>= 2*b) a %= 2*b;
    else if(b>=2*a) b %= 2*a;
    else break;
  }
  std::cout << a << " " << b << std::endl;

  return 0;
}

