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

  for (int  i = 1; i*4 <= 2000; ++i) {
    for (int  j = i; j*3+i <= 2000; ++j) {
      for (int k = j; k*2 + i + j <= 2000; ++k) {
        ll mul = i*j*k;
        ll sum = i+j+k;
        if(mul <= 1000000) continue;
        if( ((1000000*sum)%(mul-1000000))) continue;
        int l = (1000000*sum)/(mul-1000000);

        if( (sum+l)*1000000 == (mul*l) && sum+l <= 2000 && l >= k){

          printf("%d.%02d %d.%02d %d.%02d %d.%02d\n",
              i/100, i%100, j/100, j%100, k/100, k%100, l/100, l%100);
        }
      }
    }
  }

  return 0;
}

