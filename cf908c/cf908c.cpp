#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100
#define PLIMIT 10000010
#define MOD 1000000007ll
#define INF 1e9
#define EPS 1e-6
typedef long long ll;
typedef pair<ll, ll> ii;
int gcd(ll a, ll b) { return (b==0)?a:gcd(b, a%b); }
int lcm(ll a, ll b) { ll i=(a/gcd(a,b))*b; assert(i>0); return i; }
int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, r; cin >> n >> r;
  int x[1000];
  for (int i = 0; i < n; ++i) {
    cin >> x[i];
  }

  double y[1000];
  y[0] = r;
  printf("%.8f", y[0]);

  for (int i = 1; i < n; ++i) {
    if(i){
      // check all previous disk
      y[i] = r;
      double mt = r;
      for (int j = i-1; j >= 0; --j) {
        // if collision
        if(abs(x[j]- x[i]) <=  2*r){
          double tmp = sqrt(4*r*r - (x[i]-x[j])*(x[i]-x[j]));
          mt = max<double>(mt, tmp + y[j]);
        }
      }
      y[i] = mt;
    }
    // first disk
    else{
      y[i] = r;
    }
    printf(" %.8f", y[i]);
  }
  printf("\n");

  return 0;
}

