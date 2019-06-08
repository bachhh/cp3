
#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
typedef int64_t ll;
typedef pair<ll, ll> ii;
int gcd(ll a, ll b) { return (b==0)?a:gcd(b, a%b); }
int lcm(ll a, ll b) { ll i=(a/gcd(a,b))*b; assert(i>0); return i; }


int extendedEuclid(int a, int b, int &x, int &y) {
  int d;
  if (b == 0) { x = 1; y = 0; return a; }
  // base case
  d = extendedEuclid(b, a % b,x, y);
  // similar as the original gcd
  int x1 = y;
  int y1 = x - (a / b) * y;
  x = x1;
  y = y1;
  return d;
}

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  while(cin >> n && n){
    int c1, n1, c2, n2;
    cin >> c1 >> n1 >> c2 >> n2;
    int a, b;
    int g = extendedEuclid(n1, n2, a, b);
    if(n%g == 0){

      // a*n1 + b*n2 == g;
      // a*n1*k + b*n2*k == g*k = n;
      // n1*x + n2*y == n
      int k = n / g;
      a *= k; b *= k;
      k = min(a, b);

      int m = 1;
      if(a < b && a < 0){
        m = ceil((double)abs(a)/((double)n2/g));
      }
      else if( b < a  && b < 0){
      }
      else{
      }

      //std::cout << m << std::endl;
      int x = a + m*n2, y = b-m*n1;
      x *= n1, y *= n2, m = lcm(n1, n2);
      if(c2 > c1){
        k = (y-1)/m;
        y -= k*m;
        x += k*m;
      }
      else {
      }
      std::cout << x/n1 << " " << y/n2 << std::endl;
    }
    else {
      std::cout << "failed" << std::endl;
    }


  }

  return 0;
}

