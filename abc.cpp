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

  int n, k;
  cin >> n >>k;

  int t = 0;
  if(k == 0){
    for (int b = k+1; b <= n; ++b) {
      for (int r = k; r <= b ; ++r) {
        for(int c = 0; c*b+r<= n; ++c){
          int a = c*b+r;
          printf("%d = %d*%d + %d\n", a, b, c, r);
          t++;
        }
      }
    }
  }
  else {
    for (int b = k+1; b <= n; ++b) {
      for (int r = k; r < b ; ++r) {
        t+= (n-r)/b;
      }
    }
  }

  std::cout << t << std::endl;

  return 0;
}

