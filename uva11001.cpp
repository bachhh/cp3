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
  int v, v0;

  while(cin >> v >> v0 && (v||v0)){
    double maxd = 0;
    int maxdisc;
    for (int p = 1; double(v)/p > v0 ; ++p) {
      double d = 0.3*sqrt(double(v)/p - v0)*p;

      if(d <= maxd+EPS && d >= maxd-EPS){
        maxdisc = 0;
        break;
      }
      else if(d > maxd){
        maxdisc = p;
        maxd = d;
      }
    }
    std::cout << maxdisc<< std::endl;
  }

  return 0;
}

