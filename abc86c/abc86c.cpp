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
  int n;
  cin >> n;
  int t, x, y;
  int x0 = 0, y0 = 0, t0 = 0;
  for (int i = 0; i < n; ++i) {
    cin >> t >> x >> y;
    if( abs(x-x0) + abs(y-y0) > abs(t-t0)){
      std::cout << "No" << std::endl;
      return 0;
    }
    if( abs(x-x0) + abs(y-y0) < abs(t-t0) &&
       (abs(x-x0) + abs(y-y0) )%2 != (t-t0)%2){
      std::cout << "No" << std::endl;
      return 0;
    }
    x0= x;
    y0= y;
    t0= t;
  }
  std::cout << "Yes" << std::endl;

  return 0;
}

