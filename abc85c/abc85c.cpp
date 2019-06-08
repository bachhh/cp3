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

  int n, y; cin >> n >> y;
  y /= 1000;

  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= n-i; ++j) {
      int k = n-i-j;
      if(i*10 + j*5 +k == y){
        printf("%d %d %d\n", i, j, k);
        return 0;
      }

    }
  }

  printf("%d %d %d\n", -1, -1, -1);

  return 0;
}

